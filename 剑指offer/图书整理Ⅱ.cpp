// class CQueue {
// public:
//     CQueue() {}

//     void appendTail(int value) { vec.emplace_back(value); }

//     int deleteHead() {
//         if (vec.empty())
//             return -1;
//         int tmp = vec.front();
//         vec.erase(vec.begin(), vec.begin() + 1);
//         return tmp;
//     }

// private:
//     vector<int> vec;
// };

// 第二遍写
class CQueue {
public:
    CQueue() {}

    void appendTail(int value) { _q.push(value); }

    int deleteHead() {
        if (_q.empty())
            return -1;
        int tmp = _q.front();
        _q.pop();
        return tmp;
    }

private:
    queue<int> _q;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

// link : https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/description/?envType=problem-list-v2&envId=XApvNy3p