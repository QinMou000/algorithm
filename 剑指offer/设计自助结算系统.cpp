// 时间 O(1)
// 空间 O(1)
class Checkout {
public:
    // 维护一个递减的双端队列
    // 队头元素始终为当前队列的最大元素
    Checkout() {}

    int get_max() {
        if (_q.empty())
            return -1;
        return _max_queue.front();
    }

    void add(int value) {
        _q.push(value);
        // 从后向前pop掉所有小于value的值
        while (!_max_queue.empty() && _max_queue.back() < value)
            _max_queue.pop_back();
        // 将当前值插入尾部
        _max_queue.push_back(value);
    }

    int remove() {
        if (_q.empty())
            return -1;
        int Front = _q.front();
        if (_max_queue.front() == Front)
            _max_queue.pop_front();
        _q.pop();
        return Front;
    }

private:
    queue<int> _q;
    deque<int> _max_queue;
};

// link :
// https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p