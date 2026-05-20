class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        for (int left = 0, right = 0; right < n; right++) {
            // 入窗口
            sum += nums[right];
            // 判断
            while (sum >= target) {
                // 更新结果
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// link : https://leetcode.cn/problems/minimum-size-subarray-sum/