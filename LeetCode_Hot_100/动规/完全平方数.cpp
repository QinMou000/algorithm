class Solution {
public:
    int numSquares(int n) {
        // dp[i]表示组成i的最少完全平方数的个数
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        // 注意j的边界条件
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// 完全背包问题：定义 dp[i] 表示组成 i 的最少完全平方数个数
// 先选一个完全平方数 j*j（≤ i）
// 剩下的数字是 i - j*j
// 组成 i 的总个数 = 组成 i - j*j 的个数 + 1

// dp[i] = min( dp[i - 1*1] + 1,    // 选 1
//              dp[i - 2*2] + 1,    // 选 4
//              dp[i - 3*3] + 1,    // 选 9
//              ...
//              dp[i - k*k] + 1 )    // 选 k*k (k*k ≤ i)

// 重叠子问题：
// 关键观察：对于组成 i 的最优方案，假设它使用的最后一个完全平方数是 j*j（即方案中最后加上的那个平方数）。
// 去掉这个 j*j 后，剩下的部分就是 i - j*j 的一个组成方案
// 而且这个剩下的方案，一定也是组成 i - j*j 的最优方案

// 转移公式：
// dp[i] = min(dp[i - j*j] + 1)  for all j where j*j <= i

// 这其实是完全背包问题的一种：
// 物品：完全平方数 1, 4, 9, 16, ...
// 背包容量：n
// 物品重量：平方数本身
// 物品价值：1（每个平方数算 1 个）
// 目标：用最少的物品填满背包

// link : https://leetcode.cn/problems/perfect-squares/description/