class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1, n = num2.size() - 1;
        string ans;
        int cur = 0; // 进位
        while (m >= 0 || n >= 0) {
            int i = m < 0 ? 0 : num1[m] - '0';
            int j = n < 0 ? 0 : num2[n] - '0';
            int tmp = i + j + cur;
            ans += char((tmp % 10) + '0');
            cur = tmp / 10; // 处理进位
            m--, n--;
        }
        if (cur > 0)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// link : https://leetcode.cn/problems/add-strings/