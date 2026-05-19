class Solution {
public:
    string removeDuplicates(string s) {
        string stk = "";
        for (char c : s) {
            // 这里要加判空逻辑
            if (!stk.empty() && c == stk.back()) {
                stk.pop_back();
            } else {
                stk += c;
            }
        }
        return stk;
    }
};

// link : https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/