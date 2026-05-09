class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> ret(num1.size() + num2.size(), 0);
        // 不进位累加
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                ret[i + j] += x * y;
            }
        }
        // 处理进位
        int i = 0;
        while (i < ret.size() - 1) {
            ret[i + 1] += ret[i] / 10;
            ret[i] = ret[i] % 10;
            i++;
        }

        string ans = "";
        bool leadingZero = true;
        for (int k = ret.size() - 1; k >= 0; --k) {
            // 去掉前导零
            if (ret[k] == 0 && leadingZero)
                continue;
            leadingZero = false;
            ans += (char)(ret[k] + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};

// link : https://leetcode.cn/problems/multiply-strings/description/