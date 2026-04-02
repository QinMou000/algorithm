class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[105][105] = {0}; // dp[i][j]表示到达该位置有几条路经
        dp[1][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};

// link : https://leetcode.cn/problems/unique-paths/description/?envType=study-plan-v2&envId=top-100-liked