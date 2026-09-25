class Solution {
  public:
    typedef long long LL;

    int fib(int n) {
        LL dp[101];
        dp[0] = 0;
        dp[1] = 1;
        if (n <= 1)
            return dp[n];
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % (LL)(1e9 + 7);
        }
        return dp[n];
    }
};

// link : https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/description/?envType=problem-list-v2&envId=XApvNy3p