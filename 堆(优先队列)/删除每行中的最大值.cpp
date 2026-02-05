class Solution {
  public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        // 翻译:
        // 每一行找一个最大值
        // 将每一行的最大值比较出来一个极大值
        // 将极大值添加到ans里 并删掉（置零）每行的最大值
        // 返回ans

        // 翻译：把数组按行排序后 求每列最大值的和
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        return ans;
    }
};

// link https://leetcode.cn/problems/delete-greatest-value-in-each-row/description/?envType=problem-list-v2&envId=heap-priority-queue&difficulty=EASY