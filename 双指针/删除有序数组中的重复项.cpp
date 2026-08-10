class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = 1;
        while (r < n) {
            if (nums[l] == nums[r]) {
                r++;
            } else {
                l++;
                nums[l] = nums[r];
            }
        }
        return l + 1;
    }
};

// link : https://leetcode.cn/problems/remove-duplicates-from-sorted-array/