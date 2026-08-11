class Solution {
  public:
    vector<int> sockCollocation(vector<int> &sockets) {
        int ret = 0;
        for (auto e : sockets)
            ret ^= e;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;

        // 关键是找到数组中两个唯一的数的二进制中不同的位
        // 之后再利用这个位把数组中的数分成两组 分别异或

        int a = 0, b = 0;
        for (auto e : sockets) {
            if (e & div)
                a ^= e;
            else
                b ^= e;
        }
        return {a, b};
    }
};

// link :
// https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p