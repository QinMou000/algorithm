class Solution {
public:
    const static int N = 60;
    int cuttingBamboo(int bamboo_len) {
        int dp[N] = {0}; // dp[i] 表示 长度为 i的竹子切分后的乘积最大值
        for (int i = 2; i <= bamboo_len; i++) {
            int curmax = 0;               // 将 i 切分为 i - j 和 j 两个数
            for (int j = 1; j < i; j++) { // 遍历 j 的所有可能值
                // 要么 这两个数相乘 要么其中一个数再次切分乘上另一个数
                curmax = max(curmax, max((i - j) * j, (i - j) * dp[j]));
            }
            dp[i] = curmax;
        }
        return dp[bamboo_len];
    }
};

// link : https://leetcode.cn/problems/jian-sheng-zi-lcof/?envType=problem-list-v2&envId=XApvNy3p