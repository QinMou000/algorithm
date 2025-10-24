class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>(numRows, 1));
        for (int i = 0; i < numRows; i++)
            dp[i].resize(i + 1);
        // for (auto e : dp) {
        //     for (auto a : e) {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 2; i < numRows; i++) { // 行 (从零开始)
            for (int j = 1; j < i; j++) {   // 列
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp;
    }
};

// link : https://leetcode.cn/problems/pascals-triangle/?envType=study-plan-v2&envId=top-100-liked