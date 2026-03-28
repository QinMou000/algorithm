class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// 3.27腾讯暑期实习一面

// link : https://leetcode.cn/problems/maximum-subarray/description/