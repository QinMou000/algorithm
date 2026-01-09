// // 时间 O(k*nlogn)
// // 空间 O(1)
// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         int ans = 0;
//         while (k--) {
//             sort(nums.begin(), nums.end());
//             nums[0] = -nums[0];
//         }
//         for (int e : nums)
//             ans += e;
//         return ans;
//     }
// };

// 时间 O(nlogn)
// 空间 O(1)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        auto cmp = [](const int x, const int y) { return abs(x) > abs(y); };
        sort(nums.begin(), nums.end(), cmp);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k > 0 && nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
            ans += nums[i];
        }
        // 如果k没剩，那说明能转的负数都转正了，已经是最大和，返回sum
        // 如果k有剩，说明负数已经全部转正，所以如果k还剩偶数个就自己抵消掉，不用删减，如果k还剩奇数个就减掉2倍最小正数。
        return k % 2 ? ans - 2 * nums[nums.size() - 1] : ans;
    }
};
// link : https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/?envType=problem-list-v2&envId=sorting