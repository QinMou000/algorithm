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
    explicit SyncQueue(size_t cap) : capacity(cap), interrupt_flag(false) {
    }

    SyncQueue() = delete;

    SyncQueue(const SyncQueue<T> &) = delete;

    SyncQueue &operator=(const SyncQueue<T> &) = delete;

    ~SyncQueue() = default;

    void interrupt() {
        interrupt_flag = true;
        queue_not_full.notify_all();
        queue_not_empty.notify_all();
    }

    bool try_push(const T &event) {
        std::lock_guard<std::mutex> lk(queue_mutex);
        if (interrupt_flag || is_full_nolock()) {
            return false;
        }
        queue.push(event);
        queue_not_empty.notify_one();
        return true;
    }

    std::optional<T> try_pop() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        if (interrupt_flag || queue.empty()) {
            return std::nullopt;
        }
        T val = std::move(queue.front());
        queue.pop();
        queue_not_full.notify_one();
        return val;
    }

    bool push(const T &element) {
        std::unique_lock<std::mutex> lk(queue_mutex);
        queue_not_full.wait(lk, [this]() {
            return interrupt_flag.load() || (!is_full_nolock());
        });
        if (interrupt_flag) {
            return false;
        }
        queue.push(element);
        queue_not_empty.notify_one();
        return true;
    }

    std::optional<T> pop() {
        std::unique_lock<std::mutex> lk(queue_mutex);
        queue_not_empty.wait(lk, [this]() {
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

    size_t length() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        return queue.size();
    }

    bool full() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        return is_full_nolock();
    }

    bool empty() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        return queue.empty();
    }

    void clear() {
        std::lock_guard<std::mutex> lk(queue_mutex);
        while (!queue.empty()) {
            queue.pop();
        }
        queue_not_full.notify_all();
    }

private:
    bool is_full_nolock() const {
        return queue.size() >= capacity;
    }

    size_t capacity;
    std::atomic<bool> interrupt_flag;
    std::queue<T> queue;
    std::mutex queue_mutex;
    std::condition_variable queue_not_full;
    std::condition_variable queue_not_empty;
};

#endif //INC_8_22_SYNCQUEUE_H
