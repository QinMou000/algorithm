class MyCircularQueue {
public:
    MyCircularQueue(int k) : k(k + 1), vec(k + 1), start(0), end(0) {}

    bool enQueue(int value) {
        if (!isFull()) {
            // 没有满
            vec[end] = value;
            end = (end + 1) % k;
            return true;
        }
        return false;
    }

    bool deQueue() {
        if (!isEmpty()) {
            // 没有空
            start = (start + 1) % k;
            return true;
        }
        return false;
    }

    int Front() {
        if (!isEmpty()) {
            // 没有空
            return vec[start];
        }
        return -1;
    }

    int Rear() {
        if (!isEmpty()) {
            // 没有空
            int index = (end - 1 + k) % k;
            return vec[index];
        }
        return -1;
    }

    bool isEmpty() { return start == end; }

    bool isFull() { return (end + 1) % k == start; }

private:
    vector<int> vec;
    int k;
    int start;
    int end;
};

// link : https://leetcode.cn/problems/design-circular-queue/description/?envType=problem-list-v2&envId=queue&difficulty=MEDIUM