class Solution {
public:
    int longestValidParentheses(string s) {
        // 用于记录最长有效括号子串的长度
        int maxans = 0;
        // 栈中存放的是字符的下标，用于匹配括号以及计算长度
        // 栈底始终保存的是最后一个未匹配的右括号的下标（或者初始的 -1）
        stack<int> stk;
        // 初始时压入 -1，作为哨兵。这样可以统一处理有效子串从索引0开始的情况，
        // 因为当遇到第一个有效括号对时，弹出 '(' 的索引后栈顶为 -1，
        // 计算长度 i - (-1) 即 i+1，正好是正确长度。
        stk.push(-1);

        // 遍历字符串中的每一个字符
        for (int i = 0; i < s.length(); i++) {
            // 如果当前字符是 '('，将其下标压栈。
            // 栈中始终保存着“尚未匹配的左括号”或者“分隔边界”的下标。
            if (s[i] == '(') {
                stk.push(i);
            } 
            // 当前字符是 ')'
            else {
                // 弹出栈顶元素。这个栈顶可能是之前某个 '(' 的下标，
                // 也可能是之前某个无法匹配的 ')' 所留下的边界下标（比如 -1 或某个 ')' 的位置）。
                stk.pop();

                // 如果弹出后栈为空，说明当前这个 ')' 没有与之匹配的左括号，
                // 因此它成为一个新的“分隔边界”，将它自身下标压入栈中。
                // 后续的有效子串将从这个位置之后开始计算。
                if (stk.empty()) {
                    stk.push(i);
                } 
                // 弹出后栈不为空，说明找到了一个有效的括号配对：
                // 此时栈顶元素是最近一个尚未匹配的 '(' 的下标（或是边界分隔符），
                // 当前有效子串的范围就是从 (栈顶下标+1) 到 i，长度为 i - stk.top()。
                else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        // 返回最长有效括号子串的长度
        return maxans;
    }
};

// link : https://leetcode.cn/problems/longest-valid-parentheses/?envType=study-plan-v2&envId=top-100-liked