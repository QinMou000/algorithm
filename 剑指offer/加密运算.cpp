class Solution {
  public:
    int encryptionCalculate(int dataA, int dataB) {
        while (dataB) {
            int carry = (dataA & dataB) << 1; // 这里注意左移一位
            dataA ^= dataB;
            dataB = carry;
        }
        return dataA;
    }
};

// link :
// https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/description/?envType=problem-list-v2&envId=XApvNy3p