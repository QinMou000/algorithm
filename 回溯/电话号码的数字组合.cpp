class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> map;

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        dfs("", 0, n, digits);
        return ans;
    }

    void dfs(string ss, int i, int n, string& digits) {
        if (i == n) {
            ans.push_back(ss);
            return;
        }
        string str = map[digits[i]];
        for (char c : str) {
            dfs(ss + c, i + 1, n, digits);
        }
    }
};

// link : https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=problem-list-v2&envId=backtracking