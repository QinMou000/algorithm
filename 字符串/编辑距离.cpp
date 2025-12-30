class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] 表示 从word1的前i个字符变换到
        // word2的前j个字符所需的最小操作次数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                // 三种情况分别对应增删改
                dp[i][j] =
                    min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1]) // 这两个字母相同 不用操作
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
            }
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];
    }
};

// link : https://leetcode.cn/problems/edit-distance/?envType=problem-list-v2&envId=string