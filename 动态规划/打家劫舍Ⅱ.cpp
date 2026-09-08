class Solution {
  public:
    // 左闭右开
    int rob1(vector<int> &nums, int start, int end) {
        int n = nums.size();
        if (start >= n)
            return 0;
        vector<int> f(n);
        vector<int> g(n);
        f[start] = nums[start];
        g[start] = 0;

        for (int i = start + 1; i < end; ++i) {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[end - 1], g[end - 1]);
    }
    int rob(vector<int> &nums) {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));
    }
};

// link : https://leetcode.cn/problems/house-robber-ii/