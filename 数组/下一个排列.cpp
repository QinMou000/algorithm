class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2; // 倒数第二个元素
        int j = n - 1; // 倒数第一个元素
        int k = n - 1;

        // 从后往前找第一个升序序列 注意数组越界
        while (i >= 0 && nums[i] >= nums[j])
            i--, j--;

        if (i >= 0) // 说明存在下一个排列
        {
            // 从最后找到第一个比i大的位置
            while (nums[k] <= nums[i])
                k--;
            // 交换 i 和 k
            swap(nums[i], nums[k]);
        }
        // reverse j和后面的所有序列
        // 这里i == 0和i != 0都要进行交换
        for (int i = j, j = n - 1; i < j; i++, j--)
            swap(nums[i], nums[j]);
    }
};

// link : https://leetcode.cn/problems/next-permutation/description/