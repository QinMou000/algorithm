class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid]) { // [left mid] 有序
                // 如果 target 在 [left mid] 这个有序区间
                if (nums[mid] > target && nums[left] <= target) {
                    // 将right移动到mid - 1的位置 因为mid已经判断过
                    right = mid - 1;
                }
                // 如果 target 不在有序区间就让left 等于 mid + 1
                else
                    left = mid + 1;
            } else { // [mid right] 有序
                // 如果 target 在 [mid right] 这个有序区间
                if (target > nums[mid] && target <= nums[right]) { // left 和 right 是闭区间
                                                                   // 所以边界需要判断
                    left = mid + 1;
                } else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// 算法逻辑:
// if (nums[left] < nums[mid]) {
//     // [left, mid] 有序
// } else {
//     // [mid, right] 有序
// }
// ⚙️ 示例 1：无重复情况下导致误判
// nums = [3, 1]
// target = 3

// 🔹运行过程：

// left = 0, right = 1

// mid = 0, 所以 nums[left] = 3, nums[mid] = 3

// 现在：

// if (nums[left] < nums[mid])  // 3 < 3 ❌ false
// else // 执行这里

// 于是进入 “右区间有序” 分支。
// 但实际上数组 [3,1] 的左半区（只有一个元素）是有序的，我们应该在左边找 target
// = 3。 因为条件用了 <，程序会误认为“右边有序”，结果错误地去右边找，找不到返回
// -1。

// 第二遍写：
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == target)
                return m;
            if (nums[l] <= nums[m]) {
                // 左半区有序
                if (target >= nums[l] && target <= nums[m]) {
                    // tar 在左半区
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[l] > nums[m]) {
                // 右半区有序
                if (target >= nums[m] && target <= nums[r]) {
                    // tar 落在右半区
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};