class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // 递减栈，栈顶元素最小
        vector<pair<int, int>> stk; // 下标，数字
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            // 栈不为空，并且当前遍历到的元素大于栈顶元素，就可以更新结果了
            // 但不能直接更新，需要先将栈顶元素pop，维持递减栈
            // 最后将当前元素入栈
            while (!stk.empty() && stk.back().second < temperatures[i]) {
                pair<int, int> back = stk.back();
                stk.pop_back();
                ans[back.first] = i - back.first;
            }
            stk.push_back({i, temperatures[i]});
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/daily-temperatures/description/6