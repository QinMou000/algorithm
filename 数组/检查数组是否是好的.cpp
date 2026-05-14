class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for (auto e : nums) {
            if (e >= n)
                return false;
            if (e != n - 1 && cnt[e] > 0)
                return false;
            if (cnt[e] > 1)
                return false;
            cnt[e]++;
        }
        return true;
    }
};


// link : https://leetcode.cn/problems/check-if-array-is-good/description/