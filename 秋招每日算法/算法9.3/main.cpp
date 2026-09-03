#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 378. 有序矩阵中第 K 小的元素
int kthSmallest(vector<vector<int> > &matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    function<bool(int mid)> check = [&](int mid) {
        int i = n - 1, j = 0;
        int count = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += i + 1;
                j++;
            } else
                i--;
        }
        return count >= k; // true 说明答案在左上部分
    };
    int l = matrix[0][0], r = matrix[n - 1][m - 1];

    while (l < r) {
        int mid = l + (r - l) / 2;
        // 当 count < k 时, 说明mid太小了,查找范围[mid + 1, right]
        // 否则在[left, mid]范围里查找
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// 516. 最长回文子序列

// int longestPalindromeSubseq(string s) {
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     // 注意遍历顺序
//     for (int i = n - 1; i >= 0; i--) {
//         dp[i][i] = 1; // 单个字符都可以看作回文串
//         for (int j = i + 1; j < n; j++) {
//             if (s[i] == s[j])
//                 dp[i][j] = dp[i + 1][j - 1] + 2;
//             else
//                 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[0][n - 1];
// }

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    // 注意遍历顺序
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1; // 单个字符都可以看作回文串
        for (int j = i - 1; j >= 0; j--) {
            if (s[i] == s[j])
                dp[j][i] = dp[j + 1][i - 1] + 2;
            else
                dp[j][i] = max(dp[j + 1][i], dp[j][i - 1]);
        }
    }
    return dp[0][n - 1];
}

// 150. 逆波兰表达式求值
int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    int ans = 0;
    for (auto token: tokens) {
        char c = token[0];

        if (token.size() > 1 || isdigit(c)) {
            stk.push(stoi(token));
            continue;
        }
        int x = stk.top();
        stk.pop();
        if (c == '+')
            stk.top() += x;
        else if (c == '-')
            stk.top() -= x;
        else if (c == '*')
            stk.top() *= x;
        else
            stk.top() /= x;
    }
    return stk.top();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
