
class Solution {
public:
    bool ans = false;
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, i, j, word);
                    if (ans)
                        return ans;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& b, int i, int j, string word) {
        if (ans)
            return; // 剪枝
        if (word.empty()) {
            // 匹配成功
            ans = true;
            return;
        }
        int m = b.size(), n = b[0].size();
        // 范围判断
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1)
            return;

        if (b[i][j] == word[0]) {
            word.erase(word.begin());
            char tmp = b[i][j];
            b[i][j] = '#'; // 走过的地方做标记
            dfs(b, i + 1, j, word);
            dfs(b, i - 1, j, word);
            dfs(b, i, j + 1, word);
            dfs(b, i, j - 1, word);
            b[i][j] = tmp; // 恢复现场
        }
    }
};

// link : https://leetcode.cn/problems/word-search/description/?envType=study-plan-v2&envId=top-100-liked