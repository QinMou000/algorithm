class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // dp[i][j]表示走到grid[i][j]的最小总和
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][1] = 0;
        dp[1][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

// link : https://leetcode.cn/problems/0i0mDW/description/