#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>
#include <atomic>

#ifndef INC_8_22_SYNCQUEUE_H
#define INC_8_22_SYNCQUEUE_H

template<typename T>
struct SyncQueue {
public:
    // 创建固定容量的线程安全队列；容量达到 cap 后，push 会等待消费者取走元素。
    explicit SyncQueue(size_t cap) : capacity(cap), interrupt_flag(false) {
    }

    // 队列必须有明确容量，避免调用方无意间创建没有边界的缓存。
    SyncQueue() = delete;

    // mutex 和 condition_variable 不能安全地复制，因此禁止复制队列。
    SyncQueue(const SyncQueue<T> &) = delete;

    // 同上，禁止把一个队列的同步状态赋给另一个队列。
    SyncQueue &operator=(const SyncQueue<T> &) = delete;

    ~SyncQueue() = default;

    // 请求结束队列：唤醒所有可能在 push 或 pop 中等待的线程。
    // 中断后不再接收或返回元素，阻塞接口会立即结束等待。
    void interrupt() {
        interrupt_flag = true;
        queue_not_full.notify_all();
        queue_not_empty.notify_all();
    }

    // 非阻塞入队：队列已满或已中断时立即返回 false，不会等待。
    bool try_push(const T &event) {
        std::lock_guard<std::mutex> lk(queue_mutex);
        if (interrupt_flag || is_full_nolock()) {
            return false;
        }
        queue.push(event);
        // 放入新元素后通知一个正在等待数据的消费者。
        queue_not_empty.notify_one();
        return true;
    }

    // 非阻塞出队：没有元素或已中断时返回 std::nullopt，不会等待。
    std::optional<T> try_pop() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        if (interrupt_flag || queue.empty()) {
            return std::nullopt;
        }
        // 先移动队首元素，再弹出它，避免额外复制 T。
        T val = std::move(queue.front());
        queue.pop();
        // 取走元素后腾出了空间，通知一个正在等待写入的生产者。
        queue_not_full.notify_one();
        return val;
    }

    // 阻塞入队：队列满时等待；被中断后返回 false，表示元素没有写入。
    bool push(const T &element) {
        std::unique_lock<std::mutex> lk(queue_mutex);
        queue_not_full.wait(lk, [this]() {
            // wait 会在检查条件时持有 queue_mutex，可安全读取队列容量状态。
            return interrupt_flag.load() || (!is_full_nolock());
        });
        if (interrupt_flag) {
            return false;
        }
        queue.push(element);
        queue_not_empty.notify_one();
        return true;
    }

    // 阻塞出队：队列空时等待；被中断或最终仍为空时返回 std::nullopt。
    std::optional<T> pop() {
        std::unique_lock<std::mutex> lk(queue_mutex);
        queue_not_empty.wait(lk, [this]() {
            // 使用谓词可屏蔽条件变量的伪唤醒，只有可读或中断才继续执行。
            return interrupt_flag.load() || (!queue.empty());
        });
        if (interrupt_flag || queue.empty()) {
            return std::nullopt;
        }
        T val = std::move(queue.front());
        queue.pop();
        queue_not_full.notify_one();
        return val;
    }

    // 返回当前元素个数；加锁后读取，结果与队列状态一致。
    size_t length() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        return queue.size();
    }

    // 判断是否已达到容量上限。
    bool full() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        return is_full_nolock();
    }

    // 判断队列是否没有可供消费者读取的元素。
    bool empty() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        return queue.empty();
    }

    // 清空已有元素，并唤醒所有等待空间的生产者。
    // 该操作不会改变中断状态；之后仍可继续正常使用队列。
    void clear() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        while (!queue.empty()) {
            queue.pop();
        }
        queue_not_full.notify_all();
    }

private:
    // 调用方必须已持有 queue_mutex；这是供已加锁接口复用的内部判断。
    bool is_full_nolock() const {
        return queue.size() >= capacity;
    }

    // 队列最多容纳的元素数。
    size_t capacity;
    // 中断标记使用原子类型，interrupt() 可在不持有队列锁时安全设置它。
    std::atomic<bool> interrupt_flag;
    // 实际保存数据的先进先出容器。
    std::queue<T> queue;
    // 保护 queue 的读、写和容量检查。
    std::mutex queue_mutex;
    // 生产者等待“队列未满”时使用的条件变量。
    std::condition_variable queue_not_full;
    // 消费者等待“队列非空”时使用的条件变量。
    std::condition_variable queue_not_empty;
};

#endif //INC_8_22_SYNCQUEUE_H
