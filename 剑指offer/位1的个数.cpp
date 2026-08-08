class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += (n % 2);
            n = n >> 1;
        }
        return ans;
    }
};

// link :
// https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p