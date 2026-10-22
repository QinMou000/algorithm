class Solution {
  public:
    double myPow(double x, int n) {
        long long ll_n = (long long)n;
        return ll_n > 0 ? dfs(x, ll_n) : 1 / dfs(x, ll_n);
    }
    double dfs(double x, long long n) {
        if (n == 0)
            return 1.0;
        double ans = dfs(x, n / 2);
        return n % 2 == 0 ? ans * ans : ans * ans * x;
    }
};

// link :
// https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/description/?envType=problem-list-v2&envId=XApvNy3p