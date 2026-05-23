class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // dp[i][j] 表示text1的前i个元素和text2的前j个元素的最长公共子序列
        // 注意下标映射
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i < n + 1; ++i)
            for (int j = 1; j < m + 1; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[n][m];
    }
};

// link : https://leetcode.cn/problems/longest-common-subsequence/description/