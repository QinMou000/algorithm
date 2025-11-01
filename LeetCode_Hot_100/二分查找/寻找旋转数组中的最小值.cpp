class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        // 假设数组最后一个值为x
        // 发现 如果mid位置是最小值的话
        // mid的左边都是严格大于x的数
        // mid的右边都是小于等于x的数
        int x = nums[n - 1];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 假设mid落到了最小值的右边 那么mid一定是小于等于x的
            if (nums[mid] <= x)
                right = mid - 1; // 此时左移右边界
            // 假如mid落到了最小值的左边 那么mid一定严格大于x
            else
                left = mid + 1; // 此时右移左边界
        }
        return nums[left];
    }
    // int findMin(vector<int>& nums) {
    //     int n = nums.size();
    //     int left = 0, right = n - 1;
    //     int min_ans = INT_MAX;
    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         // 先判断那一边是有序的
    //         // 这个有序是指 [left, mid] [mid, right] 有序
    //         // 它们都包含了mid这个数
    //         if (nums[left] <= nums[mid]) {
    //             // 左边有序
    //             min_ans = min(min_ans, nums[left]); // 取左边的最小值比较
    //             // 之后在去右边看看有没有更小的
    //             left = mid + 1;
    //         } else {
    //             // 右边有序
    //             min_ans = min(min_ans, nums[mid]);
    //             right = mid - 1; // 右边比较完了 那也去左边看看有没有更小的
    //         }
    //     }
    //     return min_ans;
    // }

    // // 反之如果要寻找最大值:
    // int findMin(vector<int>& nums) {
    //     int n = nums.size();
    //     int left = 0, right = n - 1;
    //     int max_ans = INT_MIN;
    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         // 先判断那一边是有序的
    //         // 这个有序是指 [left, mid] [mid, right] 有序
    //         // 它们都包含了mid这个数
    //         if (nums[left] <= nums[mid]) {
    //             // 左边有序
    //             max_ans = max(max_ans, nums[mid]); // 取左边的最小值比较
    //             // 之后在去右边看看有没有更小的
    //             left = mid + 1;
    //         } else {
    //             // 右边有序
    //             max_ans = max(max_ans, nums[right]);
    //             right = mid - 1; // 右边比较完了 那也去左边看看有没有更小的
    //         }
    //     }
    //     return max_ans;
    // }
};

// link : https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked
