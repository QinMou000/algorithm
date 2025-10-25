class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> map;
        map[']'] = '[';
        map[')'] = '(';
        map['}'] = '{';
        for (char c : s) {
            if (map.count(c)) // 如果为右括号
            {
                // 如果栈为空 或者栈顶与当前括号不匹配
                if (stk.empty() || stk.top() != map[c])
                    return false;
                stk.pop(); // 如果匹配成功就出栈
            } else
                stk.push(c); // 左括号入栈
        }
        return stk.empty();
    }
};

// link : https://leetcode.cn/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-100-liked