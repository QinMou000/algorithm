class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        // dp[i] 表示以dp[i]结尾的括号的最大匹配字串长度
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 
                    (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// 如果下次做看不懂代码的话，直接看官方题解就行

// link : https://leetcode.cn/problems/longest-valid-parentheses/description/?envType=problem-list-v2&envId=dynamic-programming