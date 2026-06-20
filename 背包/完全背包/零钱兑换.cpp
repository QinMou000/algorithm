// class Solution {
// public:
//     // 回溯会超时
//     int ans = INT_MAX;
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> output;
//         dfs(coins, output, amount, 0);
//         return ans == INT_MAX ? -1 : ans;
//     }

//     void dfs(vector<int>& candidates, vector<int>& output, int target,
//              int pos) {
//         long long sum = 0;
//         int size = output.size();
//         for (auto e : output)
//             sum += e;
//         if (sum == target) {
//             ans = min(ans, size);
//             return;
//         } else if (sum > target || pos > candidates.size() - 1) {
//             return;
//         }
//         // 选择当前数字
//         output.push_back(candidates[pos]);
//         dfs(candidates, output, target, pos);
//         output.pop_back();

//         // 不选当前数字
//         dfs(candidates, output, target, pos + 1);
//     }
// };

// class Solution {
// public:
//     // 回溯会超时 用dp
//     // 这个代码也会超时
//     // dp[i][j]考虑前i枚硬币（包括i）的总和为j的最少硬币数 总和最大为 10e4
//     vector<vector<int>> dp{13, vector<int>(10005, -1)};
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         // 从最后一枚硬币开始回溯
//         int ans = dfs(coins, n - 1, amount);
//         return ans < INT_MAX / 2 ? ans : -1;
//     }
//     // 从最后一枚硬币开始算，返回所需最少硬币数量
//     // cur 当前还需多少面额
//     int dfs(vector<int>& coins, int i, int cur) {
//         if (i < 0) {
//             // cur等于0说明当前路径刚好结束，当前需要硬币数量为0
//             // cur不为0说明当前路径不满足要求，返回一个极大值
//             // 除2是为了防止下面 +1 溢出
//             return cur == 0 ? 0 : INT_MAX / 2;
//         }
//         int& ret = dp[i][cur]; // 引用
//         if (ret != -1)         // 之前计算过
//             return ret;
//         if (coins[i] > cur)
//             return dfs(coins, i - 1, cur); // 只能不选了
//         // 取选或者不选最小的
//         return min(dfs(coins, i - 1, cur), dfs(coins, i, cur - coins[i]) +
//         1);
//     }
// };

class Solution {
public:
    // 回溯会超时 用dp 完全背包
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 0x3f3f3f3f;
        // dp[i][j]使用 前 i 种硬币（即硬币下标 0, 1, ..., i-1）来凑出总金额 j
        // 所需的 最少硬币数量。
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
        return dp[n][amount] >= INF ? -1 : dp[n][amount];
    }
};

// link : https://leetcode.cn/problems/coin-change/description/