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

// 第二遍写:
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> map;
        map[']'] = '['; // 注意这里的键值对不要写反了
        map['}'] = '{';
        map[')'] = '(';
        for (char c : s) {
            if (map.count(c)) {
                // 这里判断需要注意不要写成
                //    if (!stk.empty() && stk.top() == map[c]) {
                //     // 找到了说明是右括号 判断是否和栈顶括号匹配
                //     stk.pop(); // 如果和栈顶括号匹配 就出栈
                // }
                // 栈为空 栈顶不匹配 false
                if (stk.empty() || stk.top() != map[c])
                    return false;
                // 匹配成功 出栈
                stk.pop();
            } else
                stk.push(c); // 找不到说明是左括号 入栈
        }
        return stk.empty();
    }
};

// link : https://leetcode.cn/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-100-liked