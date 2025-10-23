// 很简单，制作一张bool的二位数组用来记录“陆海情况”
// 现在引入新机制：放火。火焰会烧焦陆地，同时流窜到上下左右未烧焦的陆地。陆地被烧焦就在bool地图上标记一下。
// 遍历地图地块，如果是未烧焦的陆地，就在此地放火直到火焰完全扩散。
// 最终统计放了多少把火即可

class Solution {
public:
    // Solution() : map(300, vector<char>(300)) {}
    // vector<vector<char>> map;

    // 类内成员变量不能用括号直接初始化
    // 你可以自己写构造函数在初始化列表里面初始化 也可以这样
    // vector<vector<char>> map{300, vector<char>(300)};
    // 用 {} 初始化

    bool map[300][300] = {0};
    int m, n;
    void bfs(int i, int j) {
        // 要在 map[i][j] 位置放火 并且扩撒
        map[i][j] = false; // 当前陆地块烧焦
        if (i + 1 < m && map[i + 1][j] == true)
            bfs(i + 1, j);
        if (i - 1 >= 0 && map[i - 1][j] == true)
            bfs(i - 1, j);
        if (j + 1 < n && map[i][j + 1] == true)
            bfs(i, j + 1);
        if (j - 1 >= 0 && map[i][j - 1] == true)
            bfs(i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        cout << "fawfw" << endl;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1')
                    map[i][j] = true;
                else
                    map[i][j] = false;
        // true 表示未烧焦的陆地
        // false 表示水 或者已经烧焦的陆地
        cout << "fajifoiw" << endl;
        int fire = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (map[i][j] == true) {
                    bfs(i, j);
                    fire++; // 统计放了多少把火
                }
            }
        return fire;
    }
};

// https://leetcode.cn/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-100-liked