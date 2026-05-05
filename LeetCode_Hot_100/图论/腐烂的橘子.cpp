class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh_count = 0; // 新鲜橘子的个数
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh_count++;
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int min = 0; // 分钟数
        while (!q.empty()) {
            int cnt = q.size();
            bool is_rotten = false; // 是否bfs成功n次
            // 队列里面都是腐烂的橘子 bfs n次
            for (int i = 0; i < cnt; ++i) {
                pair<int, int> Pair = q.front();
                q.pop();
                // 分别朝四个方向上bfs
                for (auto dir : dirs) {
                    int x = Pair.first + dir.first;
                    int y = Pair.second + dir.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        // x y都在范围 并且该位置有橘子
                        grid[x][y] = 2;
                        q.push({x, y});
                        is_rotten = true;
                        fresh_count--;
                    }
                }
            }
            min = (is_rotten ? min + 1 : min);
        }

        return fresh_count ? -1 : min;
    }
};

// link : https://leetcode.cn/problems/rotting-oranges/description/?envType=study-plan-v2&envId=top-100-liked