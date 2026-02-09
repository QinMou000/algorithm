
// 暴力解法：
// 对每个格子作为右下角，向上扩展计算最大矩形面积
// 时间复杂度 O((m*n)^2)，空间复杂度 O(m*n)

// 暴力优化：
// 预处理每个格子左侧连续1的数量，减少计算面积时的重复计算
// 时间复杂度 O(m*n^2)，空间复杂度 O(m*n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)
            return 0;
        // 左侧格子连续1的数量（包含本格）
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    // 注意处理越界问题
                    left[i][j] = (j == 0 ? 1 : left[i][j - 1] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    // [i][j] 为右下角
                    int width = left[i][j];
                    int area = 0;
                    for (int k = i; k >= 0; k--) {
                        width = min(width, left[k][j]);
                        area = width * (i - k + 1);
                        ans = max(ans, area);
                    }
                }
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/maximal-rectangle/