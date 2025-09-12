// 时间复杂度O(n)
// 空间复杂度O(n)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prev_mul(n + 10); // 前缀积
//         vector<int> suf_mul(n + 10);  // 后缀积
//         prev_mul[0] = nums[0];
//         suf_mul[n - 1] = nums[n - 1];
//         // 初始化 前缀积 数组
//         for (int i = 1; i < n; i++)
//             prev_mul[i] = prev_mul[i - 1] * nums[i];
//         // 初始化 后缀积 数组
//         for (int i = n - 2; i >= 0; i--)
//             suf_mul[i] = suf_mul[i + 1] * nums[i];
//         vector<int> ans(n);
//         for (int i = 0; i < n; i++) {
//             if (i == 0)
//                 ans[i] = suf_mul[i + 1];
//             else if (i == n - 1)
//                 ans[i] = prev_mul[n - 2];
//             else
//                 ans[i] = prev_mul[i - 1] * suf_mul[i + 1];
//         }
//         return ans;
//     }
// };

// 时间复杂度O(n)
// 空间复杂度O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int prev_mul = 1, suf_mul = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prev_mul;
            prev_mul *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suf_mul;
            suf_mul *= nums[i];
        }

        return ans;
    }
};

// Link : https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked