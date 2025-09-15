class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hash;
        int max = 0;
        for (auto e : nums) {
            hash.insert(e);
            if (e > max)
                max = e;
        }
        for (int i = 1; i <= max; i++)
            if (hash.count(i) == 0)
                return i;
        return max + 1;
    }
};

// link : https://leetcode.cn/problems/first-missing-positive/?envType=study-plan-v2&envId=top-100-liked