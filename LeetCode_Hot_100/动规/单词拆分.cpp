class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto& str : wordDict)
            dict.insert(str);
        int n = s.size();
        vector<bool> dp(n + 1, false); // dp[i]=true表示s的[0,i)可以由dict拼接
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            // j 为下一个单词的起始位置
            for (int j = 0; j < i; ++j) {
                // dp[j] 就表示 [0,j) 是否满足要求
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// link : https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-100-liked