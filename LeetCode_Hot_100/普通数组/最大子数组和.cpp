class Solution {
public:
    static const int N = 1e5 + 10;
    int dp[N] = {0}; // 以 dp[i] 为结尾的最大连续子数组和
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ans = dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = dp[i] > ans ? dp[i] : ans;
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked