// 17.14. 最小K个数
vector<int> smallestK(vector<int> &arr, int k) {
    priority_queue<int> pq;
    for (auto e : arr) {
        pq.push(e);
        if (pq.size() > k)
            pq.pop();
    }
    vector<int> ans;
    while (pq.size()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// 1143. 最长公共子序列
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    // text1 的前 i 个字符与 text2 的前 j 个字符的最长公共子序列长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // i == j
    // dp[i][j] = dp[i - 1][j - 1] + 1;
    // i != j
    // dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// 875. 爱吃香蕉的珂珂
class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = 0;
        for (auto pile : piles) {
            r = max(r, pile);
        }
        while (l < r) {
            int speed = l + (r - l) / 2;
            long cost_time = GetTime(piles, speed);
            if (cost_time <= h) {
                r = speed;
            } else {
                l = speed + 1;
            }
        }
        return l;
    }
    long GetTime(vector<int> &piles, int speed) {
        long time = 0;
        for (auto pile : piles) {
            // 计算每一堆花费的时间 向上取整
            // 例如一堆有 7 根香蕉，速度为每小时吃 3 根
            // - 第 1 小时：吃 3 根
            // - 第 2 小时：吃 3 根
            // - 第 3 小时：吃 1 根
            // 实际需要 3 小时，而 7 / 3 = 2
            int cur_time = (pile + speed - 1) / speed;
            time += cur_time;
        }
        return time;
    }
};

// 115. 不同的子序列

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int m = s.size(), n = t.size();
//         if (m < n)
//             return 0;
//         // 用 s 的前 i 个字母组成 t 的前 j 个字母的方案数
//         vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
//         for (int i = 0; i <= m; i++)
//             dp[i][0] = 1; // 每一个 s 前缀都有一个空串前缀

//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 // 可以选择 s 当前字符 也可以不选
//                 if (s[i - 1] == t[j - 1])
//                     dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % INT_MAX;
//                 // 只能不选 s 当前字符
//                 else
//                     dp[i][j] = dp[i - 1][j];
//             }
//         }
//         return dp[m][n];
//     }
// };

// 空间优化版
class Solution {
  public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;
        // 用 s 的前 i 个字母组成 t 的前 j 个字母的方案数
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // 每一个 s 前缀都有一个空串前缀

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                // 可以选择 s 当前字符 也可以不选
                if (s[i - 1] == t[j - 1])
                    dp[j] = (dp[j] + dp[j - 1]) % INT_MAX;
                // // 只能不选 s 当前字符
                // else
                //     dp[j] = dp[j];
            }
        }
        return dp[n];
    }
};