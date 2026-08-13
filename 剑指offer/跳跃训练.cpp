class Solution {
  public:
    typedef long long LL;
    int trainWays(int num) {
        LL dp[101];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        if (num <= 2)
            return dp[num];
        for (int i = 3; i <= num; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % (LL)(1e9 + 7);
        }
        return dp[num];
    }
};
// link :
// https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/description/?envType=problem-list-v2&envId=XApvNy3p