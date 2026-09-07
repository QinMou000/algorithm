#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 64. 最小路径和 一维空间优化
int minPathSum(vector<vector<int>> &grid) {
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

// 416. 分割等和子集
bool canPartition(vector<int> &nums) {
    int sum = 0, max_num = 0, n = nums.size();
    for (auto e : nums) {
        sum += e;
        max_num = max(e, max_num);
    }
    if (sum % 2 == 1)
        return false;
    if (max_num > sum / 2)
        return false;
    int target = sum / 2;
    // 在数组的前i个数中选择一些数,是否存在一种方案,使得之和恰好等于j
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= nums[i])
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n - 1][target];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
