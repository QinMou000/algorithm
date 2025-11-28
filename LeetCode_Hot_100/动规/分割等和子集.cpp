// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) {
//             return false;
//         }
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int maxNum = *max_element(nums.begin(), nums.end());
//         if (sum & 1) {
//             return false;
//         }
//         int target = sum / 2;
//         if (maxNum > target) {
//             return false;
//         }
//         vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//         for (int i = 0; i < n; i++) {
//             dp[i][0] = true;
//         }
//         dp[0][nums[0]] = true;
//         for (int i = 1; i < n; i++) {
//             int num = nums[i];
//             for (int j = 1; j <= target; j++) {
//                 if (j >= num) {
//                     dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
//                 } else {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }
//         return dp[n - 1][target];
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& e : nums)
            sum += e;
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++)
            for (int j = sum; j >= nums[i]; j--)
                dp[j] = dp[j] | dp[j - nums[i]];
        return dp[sum];
    }
};
// 搞清楚状态表示

// link : https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=study-plan-v2&envId=top-100-liked

// 题解 : https://leetcode.cn/problems/partition-equal-subset-sum/solutions/442320/fen-ge-deng-he-zi-ji-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked