class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk; // 存下标 递增栈 用于找左右第一个严格小于栈顶元素的元素
        int ans = 0;
        // 首尾元素都加一个零
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            // while循环完之后i位置肯定可以入栈并且不破坏递增
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int cur = stk.top();
                stk.pop();
                // cur左边能扩展到的最远
                int left = stk.top() + 1;
                // cur右边能扩展到的最远
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            stk.push(i); // 始终记住存的是下标
        }
        return ans;
    }
};

feat 柱状图中最大的矩形 单调递增栈 找左边第一个比当前位置小的元素

// link : https://leetcode.cn/problems/largest-rectangle-in-histogram/description/