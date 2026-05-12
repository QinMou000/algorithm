class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1;
        stack<char> stk2;
        for (auto c : s) {
            if (c != '#')
                stk1.push(c);
            else if (!stk1.empty()) // 注意多个#的情况下 判空
                stk1.pop();
        }
        for (auto c : t) {
            if (c != '#')
                stk2.push(c);
            else if (!stk2.empty())
                stk2.pop();
        }
        return stk1 == stk2;
    }
};