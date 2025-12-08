class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (str[i] == ' ')
            i++;
        int sign = 1; // 符号位
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+')
            i++;
        long long ans = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            int val = str[i] - '0';
            ans = ans * 10 + sign * val;
            i++;
            if (ans > INT_MAX)
                ans = INT_MAX;
            if (ans < INT_MIN)
                ans = INT_MIN;
        }
        return (int)ans;
    }
};

// link : https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/?envType=problem-list-v2&envId=XApvNy3p