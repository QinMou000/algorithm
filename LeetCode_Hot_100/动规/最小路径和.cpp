class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] 表示到达这个位置的最小路径和
        int dp[205][205];
        int m = grid.size();
        int n = grid[0].size();
        for (int k = 2; k < 205; k++)
            dp[k][0] = dp[0][k] = INT_MAX;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

// link : https://leetcode.cn/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked