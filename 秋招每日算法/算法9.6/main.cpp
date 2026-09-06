#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 64. 最小路径和 一维空间优化
int minPathSum(vector<vector<int> > &grid) {
    int n = grid[0].size(), m = grid.size();
    // 走到当前格子的最小权值
    vector<int> dp(n + 1, 0);
    dp[0] = INT_MAX;
    dp[1] = grid[0][0];
    for (int j = 2; j <= n; j++)
        dp[j] = dp[j - 1] + grid[0][j - 1];

    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i - 1][j - 1];
        }
    }

    return dp[n];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
