class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (grid[i][j] == 0)
            return 0;

        int ans = 1;    // 当前格子是陆地
        grid[i][j] = 0; // 将当前格子置零
        if (i + 1 < m)
            ans += dfs(grid, i + 1, j);
        if (i - 1 >= 0)
            ans += dfs(grid, i - 1, j);
        if (j + 1 < n)
            ans += dfs(grid, i, j + 1);
        if (j - 1 >= 0)
            ans += dfs(grid, i, j - 1);
        return ans;
    }
};

// link : https://leetcode.cn/problems/max-area-of-island/description/