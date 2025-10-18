// class Solution {
// public: // 暴力解法
//     int searchInsert(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//         // 分别处理如下三种情况
//         // 目标值在数组所有元素之前
//         // 目标值等于数组中某一个元素
//         // 目标值插入数组中的位置
//             if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
//                 return i;
//             }
//         }
//         // 目标值在数组所有元素之后的情况
//         return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
//     }
// };

// class Solution {
// public: // 第一种左闭右开区间
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0;
//         int right = n; // 定义target在左闭右开的区间里，[left, right)  target
//         while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
//             int middle = left + ((right - left) >> 1);
//             if (nums[middle] > target) {
//                 right = middle; // target 在左区间，在[left, middle)中
//             } else if (nums[middle] < target) {
//                 left = middle + 1; // target 在右区间，在 [middle+1, right)中
//             } else { // nums[middle] == target
//                 return middle; // 数组中找到目标值的情况，直接返回下标
//             }
//         }
//         // 分别处理如下四种情况
//         // 目标值在数组所有元素之前 [0,0)
//         // 目标值等于数组中某一个元素 return middle
//         // 目标值插入数组中的位置 [left, right) ，return right 即可
//         // 目标值在数组所有元素之后的情况 [left, right)，这是右开区间，return right 即可
//         return right;
//     }
// };

// class Solution {
// public: // 第二种左闭右闭区间
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0;
//         int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
//         while (left <= right) { // 当left==right，区间[left, right]依然有效
//             int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
//             if (nums[middle] > target) {
//                 right = middle - 1; // target 在左区间，所以[left, middle - 1]
//             } else if (nums[middle] < target) {
//                 left = middle + 1; // target 在右区间，所以[middle + 1, right]
//             } else { // nums[middle] == target
//                 return middle;
//             }
//         }
//         // 分别处理如下四种情况
//         // 目标值在数组所有元素之前  [0, -1]
//         // 目标值等于数组中某一个元素  return middle;
//         // 目标值插入数组中的位置 [left, right]，return  right + 1
//         // 目标值在数组所有元素之后的情况 [left, right]，这是右闭区间，所以  return right + 1
//         return right + 1;
//     }
// };

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // 左闭右闭 [left, right]

        while (left <= right) { // 因为 left 如果等于 right 仍然是一个有效空间
            int mid = left + (right - left) / 2; // 避免 left + right 数据溢出
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1; // target 在左区间 [left, mid - 1]
            else
                left = mid + 1; // target 在右区间 [mid + 1, right]
        }
        // cout << left << " " << right << endl;
        // 循环结束后 left > right
        // return left;
        return right + 1;
    }
};

// link : https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked