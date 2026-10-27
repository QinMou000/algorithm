// 131. 分割回文串
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    // 从当前位置开始不断地选下一个回文字符
    function<void(int)> dfs = [&](int pos) {
        if (pos == s.size()) {
            ans.emplace_back(path);
        }
        for (int i = pos; i < s.size(); i++) {
            string tmp = s.substr(pos, i - pos + 1);
            if (check(tmp)) {
                path.emplace_back(tmp);
                dfs(i + 1);
                path.pop_back();
            }
        }
    };
    dfs(0);
    return ans;
}
bool check(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

// 221. 最大正方形
int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // 以 i j 为正方形的右下角 最大正方形的边长
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == '1')
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            ans = max(ans, dp[i][j] * dp[i][j]);
        }
    }
    return ans;
}

// 516. 最长回文子序列

// int longestPalindromeSubseq(string s) {
//     // 在 i-j 之间的最长回文子序列的长度为 dp[i][j]
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for (int i = n - 1; i >= 0; i--) {
//         dp[i][i] = 1; // 每一个字符都是长度为 1 的回文串
//         for (int j = i + 1; j < n; j++) {
//             if (s[i] == s[j])
//                 dp[i][j] = dp[i + 1][j - 1] + 2;
//             else
//                 dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
//         }
//     }
//     return dp[0][n - 1];
// }

// 空间优化
int longestPalindromeSubseq(string s) {
    // 在 i-j 之间的最长回文子序列的长度为 dp[i][j]
    int n = s.size();
    vector<int> dp(n, 0);
    int tmp = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1; // 每一个字符都是长度为 1 的回文串
        int prev = 0;
        for (int j = i + 1; j < n; j++) {
            int tmp = dp[j];
            if (s[i] == s[j])
                dp[j] = prev + 2;
            else
                dp[j] = max(dp[j - 1], dp[j]);
            prev = tmp;
        }
    }
    return dp[n - 1];
}

// 82. 删除排序链表中的重复元素 II
ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dump = new ListNode((int)0x3f3f3f3f, head);
    ListNode *cur = dump;
    ListNode *prev = nullptr;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            while (cur->next && cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            prev->next = cur->next;
            cur = cur->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dump->next;
}

// 240. 搜索二维矩阵 II
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (target == matrix[i][j])
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}