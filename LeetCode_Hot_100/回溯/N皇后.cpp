class Solution {
  public:
    // 对于 ↗ 方向的格子，行号加列号是不变的。
    // 对于 ↖ 方向的格子，行号减列号是不变的。
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        string s(n, '.');
        vector<string> board(n, s); // 开始棋盘为空

        // col 标记之前皇后被放在过哪些列
        // check1 check2分别标记之前放置的皇后的行号加列号，以及行号减列号
        vector<bool> col(n, false), check1(n * 2, false), check2(n * 2, false);
        // row表示当前要把皇后放在第 row行
        auto dfs = [&](this auto &&dfs, int row) {
            if (row == n) {
                ans.emplace_back(board);
                return;
            }

            for (int c = 0; c < n; ++c) {
                int rc = row - c + n - 1; // 计算行列相减（再加n - 1是为了把负数映射为非负下标）
                if (!col[c] && !check1[row + c] && !check2[rc]) {
                    // 皇后放在当前位置不会受到攻击
                    board[row][c] = 'Q';
                    col[c] = check1[row + c] = check2[rc] = true;
                    dfs(row + 1);
                    // 恢复现场
                    board[row][c] = '.';
                    col[c] = check1[row + c] = check2[rc] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};

// 第二遍写：
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    string str(n, '.');
    vector<string> output(n, str);

    vector<bool> col(n, false), check1(2 * n, false), check2(2 * n, false);
    // 放第 row 行的皇后
    auto dfs = [&](this auto &&dfs, int row) {
        if (row == n) {
            ans.emplace_back(output);
            return;
        }
        // 在第 row 行中遍历所有列
        for (int i = 0; i < n; i++) {
            int rc = row - i + n - 1; // row - col + n - 1，映射为非负下标
            // 这一列没人、这条 ↘ 对角线没人、这条 ↙ 对角线没人
            if (!col[i] && !check1[rc] && !check2[row + i]) {
                // 可以在 [row][i] 位置放皇后
                col[i] = true;
                check1[rc] = true;
                check2[row + i] = true;
                output[row][i] = 'Q';
                dfs(row + 1); // 下一行
                // 恢复现场
                output[row][i] = '.';
                col[i] = false;
                check1[rc] = false;
                check2[row + i] = false;
            }
        }
    };
    dfs(0);
    return ans;
}

// link : https://leetcode.cn/problems/n-queens/description/?envType=study-plan-v2&envId=top-100-liked