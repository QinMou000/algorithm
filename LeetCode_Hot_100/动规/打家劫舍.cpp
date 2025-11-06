class Solution {
public:
    int rob(vector<int>& nums) {
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

// link : https://leetcode.cn/problems/house-robber/description/?envType=study-plan-v2&envId=top-100-liked