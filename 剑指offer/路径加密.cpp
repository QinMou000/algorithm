class Solution {
public:
    string pathEncryption(string str) {
        for (auto& s : str)
            if (s == '.')
                s = ' ';
        return str;
    }
};

// link : https://leetcode.cn/problems/ti-huan-kong-ge-lcof/?envType=problem-list-v2&envId=XApvNy3p