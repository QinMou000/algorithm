class Solution {
  public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (target == nums[m])
                return true;
            if (nums[m] > nums[l]) {
                // 左半区有序
                if (target >= nums[l] && target <= nums[m]) {
                    // tar 落在有序半区
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[l] > nums[m]) {
                // 右半区有序
                if (target >= nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                // 当 nums [l] == nums [m] 无法判断哪边有序时，
                // 直接 l++ 缩小左边界去重
                l++;
            }
        }
        return false;
    }
};

// link : https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/