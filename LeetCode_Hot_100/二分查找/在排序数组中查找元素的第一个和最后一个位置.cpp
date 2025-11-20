class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = -1, end = -1;

        // 查找右边界
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                // 找到 mid 后往两边寻找边界
                begin = mid, end = mid;
                // 此时左边界下标必须大于前一次二分的左边界下标
                while (begin > left && target == nums[begin - 1])
                    begin--; // 如果左边的位置满足两个条件 再减减
                // 同样 此时右边界下标必须小于前一次二分的右边界下标
                while (end < right && target == nums[end + 1])
                    end++;
                break; // 已经找到左右边界 无需再次二分
            } else if (target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return {begin, end};
    }
};

// link : https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked

// 第二遍写
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left; // 这样求出来的是左边界
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int begin = lower_bound(nums, target); // 求左边界
        if (nums.size() == begin || nums[begin] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1; // 求右边界
        return {begin, end};
    }
};

// link :
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked