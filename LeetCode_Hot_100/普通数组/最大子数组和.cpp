class Solution {
public:
    static const int N = 1e5 + 10;
    int dp[N] = {0}; // 以 dp[i] 为结尾的最大连续子数组和
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ans = dp[0] = nums[0]; // 初始化
        for (int i = 1; i < n; i++) {
            // 区分nums[i] 大于零 和小于等于零 两种情况
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = dp[i] > ans ? dp[i] : ans; // 更新结果
        }
        return ans;
    }
};

// 第二遍写

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n); // dp[i] 以i结尾的子数组的和中最大值
//         dp[0] = nums[0];
//         for (int i = 1; i < n; i++) {
//             dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//         }
//         int ans = INT_MIN;
//         for (auto e : dp)
//             ans = max(ans, e);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int pre_sum = 0, ans = nums[0];
//         for (int i = 0; i < n; i++) {
//             pre_sum = max(pre_sum + nums[i], nums[i]);
//             ans = max(pre_sum, ans);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    typedef struct Status {
        // lSum 表示 [l,r] 内以 l 为左端点的最大子段和
        // rSum 表示 [l,r] 内以 r 为右端点的最大子段和
        // mSum 表示 [l,r] 内的最大子段和
        // iSum 表示 [l,r] 的区间和
        int lSum, rSum, mSum, iSum;
    } Stat;
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
    Stat get(vector<int>& nums, int l, int r) {
        if (l == r)
            return Stat(nums[l], nums[l], nums[l], nums[l]);
        int m = (l + r) >> 1;
        Stat lS = get(nums, l, m);
        Stat rS = get(nums, m + 1, r);
        return pushUp(lS, rS);
    }
    // 将左右区间的Stat维护为当前区间的Stat
    Stat pushUp(Stat lS, Stat rS) {
        // 区间 [l,r] 的 iSum 就等于
        // 「左子区间」的 iSum 加上「右子区间」的 iSum。
        int iSum = lS.iSum + rS.iSum;
        // 对于 [l,r] 的 lSum，存在两种可能，它要么等于「左子区间」的
        // lSum，要么等于「左子区间」的 iSum 加上「右子区间」的 lSum，二者取大。
        int lSum = max(lS.lSum, lS.iSum + rS.lSum);
        int rSum = max(rS.rSum, rS.iSum + lS.rSum);
        // 当计算好上面的三个量之后，就很好计算 [l,r] 的 mSum 了。
        // 我们可以考虑 [l,r] 的 mSum 对应的区间是否跨越 m——它可能不跨越 m，
        // 也就是说 [l,r] 的 mSum 可能是「左子区间」的 mSum 和 「右子区间」的
        // mSum 中的一个； 它也可能跨越 m，可能是「左子区间」的 rSum 和
        // 「右子区间」的 lSum 求和。三者取大
        int mSum = max(max(lS.mSum, rS.mSum), lS.rSum + rS.lSum);
        return (Stat){lSum, rSum, mSum, iSum};
    }
};


// link : https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked