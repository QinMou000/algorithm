class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // 题目没有让我们求子数组的范围，只需返回最大乘积即可
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        // 负数乘以负数，会变成正数，所以我们需要维护两个变量
        int Max, Min, ans; // 分别为当前的最大值和最小值
        Max = Min = ans = nums[0];
        for (int i = 1; i < n; ++i) {
            int tmp = Max;
            // 最小值可能为负数，但没准下一步乘以一个负数，当前的最大值就变成最小值，而最小值则变成最大值
            // 如果nums[i] == 0需要断开从i + 1位置重新开始
            Max = max(max(Max * nums[i], nums[i]), Min * nums[i]);
            Min = min(min(Min * nums[i], nums[i]), tmp * nums[i]);
            ans = max(ans, Max);
        }
        return ans;
    }
};

```py
def maxProduct(self, nums: List[int]) -> int:
    max_p = nums[0]        # 全局最大值初始化为数组第一个数
    first_neg = 0          # 标记当前分段第一个负前缀积，0=无负数
    pre_p = 1              # 分段前缀积，每段从1开始相乘
    for num in nums:
        pre_p = pre_p * num          # 更新当前前缀积
        max_p = max(max_p, pre_p)    # 情况1：整个前缀子数组乘积更大，更新答案

        # 当前前缀积为负数
        if pre_p < 0 and first_neg == 0:
            # 分段里第一次出现负前缀，记录这个值
            first_neg = pre_p
        elif pre_p < 0:
            # 已经存在第一个负前缀，去掉第一个负数前的区间，乘积转正
            # pre_p / first_neg = [第一个负数后 ~ 当前] 的子数组乘积
            max_p = max(max_p, int(pre_p / first_neg))
        
        # 遇到0，分段截断，重置前缀积、负标记，开启新分段
        if num == 0:
            pre_p = 1
            first_neg = 0
    return max_p
```

// link : https://leetcode.cn/problems/maximum-product-subarray/description/?envType=study-plan-v2&envId=top-100-liked