class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // left 表示最左边为零的数
        // right 表示已经遍历的最后一个数 判断是否为零即可
        int left = 0, right = 0;
        while (right < n) {
            if (nums[right] != 0)
                swap(nums[left++], nums[right]);
            right++;
        }
    }
};

// link : https://leetcode.cn/problems/move-zeroes/?envType=study-plan-v2&envId=top-100-liked