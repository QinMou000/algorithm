class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        long long dp[1005];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        if (bamboo_len <= 6)
            return dp[bamboo_len];
        for (int i = 7; i <= bamboo_len; i++) {
            dp[i] = (dp[i - 3] * 3) % 1000000007;
        }
        return dp[bamboo_len];
    }
};

// link : https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/description/?envType=problem-list-v2&envId=XApvNy3p

// // 实际上，这个问题可以通过数学分析得出最优解：
// // 当长度大于 4 时，切割成尽可能多的 3，剩余部分为 2 时乘积最大
// // 证明：3×3 > 2×2×2，且 3×2 > 5

// 不能直接套用 砍竹子Ⅰ的解法
// class Solution {
// public:
//     int cuttingBamboo(int bamboo_len) {
//         long long dp[1005] = {0}; // dp[i] 表示 长度为 i的竹子切分后的乘积最大值
//         for (long long i = 2; i <= bamboo_len; i++) {
//             long long curmax = 0;               // 将 i 切分为 i - j 和 j 两个数
//             for (long long j = 1; j < i; j++) { // 遍历 j 的所有可能值
//                 // 要么 这两个数相乘 要么其中一个数再次切分乘上另一个数
//                 curmax = max(curmax, max((i - j) * j, (i - j) * dp[j]));
//             }
//             dp[i] = curmax % 1000000007;
//         }
//         return dp[bamboo_len];
//     }
// };