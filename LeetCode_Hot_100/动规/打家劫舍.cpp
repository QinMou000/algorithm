class Solution {
  public:
    int rob(vector<int> &nums) {
        int dp[105] = {0}; // 偷这一家时 最大收获
        int n = nums.size();
        dp[0] = nums[0];
        if (n > 1)
            dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

// 第二遍写：
class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n + 1); // 打劫当前这家店
        vector<int> g(n + 1); // 不打劫这家店
        f[0] = nums[0];
        g[0] = 0;
        for (int i = 1; i < n; i++) {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};

// link : https://leetcode.cn/problems/house-robber/description/?envType=study-plan-v2&envId=top-100-liked