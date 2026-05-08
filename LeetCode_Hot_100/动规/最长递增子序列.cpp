class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0); // 表示以i为结尾的最长递增子序列
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};


// 如果要返回完整序列应该怎么做？
class Solution {
public:
    vector<int> lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        // 表示以i为结尾的最长递增子序列长度
        vector<int> dp(n, 0);
        // prev[j]记录以j位置结尾的最长序列的前一个序列的下标
        vector<int> prev(n, -1);
        int max_len = 0;
        int end_pos = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    prev[i] = j; // 以i为结尾的最长序列的前一个位置的下标是j
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                end_pos = i;
            }
        }

        vector<int> ans;
        int i = end_pos;
        // endpos往前跳一直到-1
        while (prev[i] != -1) {
            ans.push_back(pre[i]);
            i = prev[i];
        }
        // 翻转数组
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// link : https://leetcode.cn/problems/longest-increasing-subsequence/?envType=study-plan-v2&envId=top-100-liked