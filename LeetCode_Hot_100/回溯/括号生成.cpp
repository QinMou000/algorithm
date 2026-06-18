class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string output = "";
        dfs(output, 0, 0, n);
        return ans;
    }
    void dfs(string output, int left, int right, int n) {
        if (right > left || left > n) // 减枝 出现 ())) 这种 或者n = 3 但output为(((( 都不要
            return;
        if (left == n && right == n) {
            ans.emplace_back(output);
            return;
        }
        dfs(output + '(', left + 1, right, n);
        dfs(output + ')', left, right + 1, n);
    }
};
// -----------------------------------------------------------------------------------------------
class Solution {
    bool valid(const string& str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(')
                ++balance;
            else
                --balance;
            if (balance < 0)
                return false;
        }
        return balance == 0;
    }

    void generate_all(string current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        generate_all(current + "(", n, result);
        generate_all(current + ")", n, result);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};


// link : https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-100-liked