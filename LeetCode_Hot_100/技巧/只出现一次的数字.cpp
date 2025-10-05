class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto& e : nums)
            ans ^= e;
        return ans;
    }
};

// link : https://leetcode.cn/problems/single-number/?envType=study-plan-v2&envId=top-100-liked