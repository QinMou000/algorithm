class Solution {
public:
    string minWindow(string s, string t) {
        int hash[128] = {0};
        int kinds = 0;
        for (auto c : t)
            if (hash[c]++ == 0)            // 统计每一种字符出现了多少次
                kinds++;                   // 统计有多少种字符
        int pos, len = INT_MAX, count = 0; // 维护 l - r 中有多少种字符;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (--hash[s[r]] == 0)     // 进窗口后判断
                count++;               // 表示有效字符加一
            while (count == kinds) {   // l - r 中的有效字符等于 t 中的字符
                if (r - l + 1 < len) { // 更新结果
                    len = r - l + 1;
                    pos = l;
                }
                if (hash[s[l++]]++ == 0) // 出窗口
                    count--;             // 表示有效字符减一
            }
        }
        return len == INT_MAX ? "" : s.substr(pos, len);
    }
};