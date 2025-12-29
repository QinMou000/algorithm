class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans;
        int diff = INT_MAX; // 差值
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1; // 左闭右闭
            while (left < right) {
                int cun_sum = nums[left] + nums[right] + nums[i];
                int cur_diff = abs(cun_sum - target);
                if (cur_diff < diff) {
                    diff = cur_diff;
                    ans = cun_sum;
                }
                if (cun_sum > target)
                    right--;
                else if (cun_sum < target)
                    left++;
                else if (cun_sum == target)
                    return cun_sum;
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/3sum-closest/