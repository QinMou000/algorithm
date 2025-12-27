class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> stk; // 辅助栈
        int j = 0;      // 对于poped的索引
        for (int i = 0; i < putIn.size(); i++) {
            stk.emplace(putIn[i]);
            // 如果辅助栈不为空&&top与当前要取出的元素相等
            while (!stk.empty() && stk.top() == takeOut[j])
                stk.pop(), j++;
        }
        return stk.empty();
    }
};

// link : https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/?envType=problem-list-v2&envId=XApvNy3p

// 注意：本题与主站 946 题相同：https://leetcode.cn/problems/validate-stack-sequences/