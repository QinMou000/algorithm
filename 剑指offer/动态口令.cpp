class Solution {
public:
    string dynamicPassword(string password, int target) {
        int x = password.size() - target; // 算出需要轮转的次数
        reverse(password.begin(), password.end());
        reverse(password.begin(), password.begin() + x);
        reverse(password.begin() + x, password.end());
        return password;
    }
};

// link : https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/?envType=problem-list-v2&envId=XApvNy3p