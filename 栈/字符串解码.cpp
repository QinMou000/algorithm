class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        // pair 里存的是：<左括号前的倍数, 左括号前的字符串>
        stack<pair<int, string>> stk;
        int time = 0;    // 记录当前的倍数（注意初始化为 0）
        string res = ""; // 记录当前的字符串
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                // 处理多位数字
                time = time * 10 + (c - '0');
            } else if (c >= 'a' && c <= 'z') {
                // 如果是字母，直接加到当前 res
                res += c;
            } else if (c == '[') {
                // 遇到 '['，开始存档，并清空当前状态给括号内使用
                stk.push({time, res});
                res = "";
                time = 0;
            } else if (c == ']') {
                // 遇到 ']'，提取存档
                auto Pair = stk.top();
                stk.pop();
                // 将括号里的内容 (也就是现在的 result) 翻倍
                string tmp = "";
                for (int j = 0; j < Pair.first; j++)
                    tmp += res;
                // 拼接到进括号前的历史字符串后面，成为新的 result
                res = Pair.second + tmp;
            }
        }
        return res;
    }
};

// link : https://leetcode.cn/problems/decode-string/description/