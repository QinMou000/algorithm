// class Solution {
// public:
// // 数组翻转
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k %= n;
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin() + k);
//         reverse(nums.begin() + k, nums.end());
//     }
// };
// class Solution {
// public:
// //  超时了
//     void rotate_left_once(vector<int>& nums) {
//         int n = nums.size();
//         int x = nums.back();
//         for (int i = n - 1; i > 0; i--)
//             nums[i] = nums[i - 1];
//         nums.erase(nums.begin());
//         nums.insert(nums.begin(), x);
//     }
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k %= n;
//         while (k--)
//         rotate_left_once(nums);
//     }
// };
class Solution {
public:
    // 额外数组
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i)
            newArr[(i + k) % n] = nums[i];
        nums.assign(newArr.begin(), newArr.end());
    }
};
// link : https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked