class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // 多开一行一列空间
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // 当字符串 s 和模式 p 均为空时 匹配成功

        // dp[i][0]=false 即空模式无法匹配非空字符串

        for (int j = 1; j <= n; ++j) {
            // 只有当模式 p 的前 j 个字符均为星号时 dp[0][j] 才为真
            if (p[j - 1] == '*')
                dp[0][j] = true;
            else
                break;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

// link : https://leetcode.cn/problems/wildcard-matching/description/