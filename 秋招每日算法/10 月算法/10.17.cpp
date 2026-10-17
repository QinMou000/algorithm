// 329. 矩阵中的最长递增路径

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    // 计算以 i j 为起点的最长递增路径 并存入 memo
    function<int(int, int)> dfs = [&](int i, int j) {
        int ret = 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
                ret = max(ret, dfs(x, y) + 1);
        }
        memo[i][j] = max(ret, memo[i][j]);
        return ret;
    };
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    return ans;
}