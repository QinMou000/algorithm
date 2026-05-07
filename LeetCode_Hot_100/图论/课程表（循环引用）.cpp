class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(numCourses);

        // 邻接表构建有向图
        for (auto& e : prerequisites) {
            matrix[e[1]].push_back(e[0]);
        }
        // 定义状态数组
        // 0 未被访问
        // 1 正在访问
        // 2 已经被访问过
        vector<int> color(numCourses, 0);
        // 返回true表示找到环
        auto dfs = [&](this auto&& dfs, int x) -> bool {
            color[x] = 1;
            // 遍历x的邻居
            for (auto e : matrix[x]) {
                // 情况一：colors[y] == 1，表示发生循环依赖，找到了环
                // 情况二：colors[y] == 0，没有访问过 y，继续递归 y 获取信息
                // 情况三：colors[y] == 2，重复访问 y
                // 只会重蹈覆辙，和之前一样无法找到环，跳过
                if (color[e] == 1 || color[e] == 0 && dfs(e))
                    return true;
            }
            // x这一条线已经全部访问完
            color[x] = 2;
            return false; // 没有找到环
        };

        for (int i = 0; i < numCourses; ++i)
            if (color[i] == 0 && dfs(i))
                return false; // 有环
        return true;          // 无环
    }
};
// 腾讯暑期一面
// link : https://leetcode.cn/problems/course-schedule/description/?envType=study-plan-v2&envId=top-100-liked