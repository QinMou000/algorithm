class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = m - 1; i >= 0; --i)
            for (int j = 0; j <= n - 1; ++j) {
                if (i == j)
                    break;
                swap(matrix[i][j], matrix[j][i]);
            }
    }
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 矩阵转置 link : https://leetcode.cn/problems/transpose-matrix/
        transpose(matrix);
        // 以垂直线进行翻转
        int left = 0, right = n - 1;
        while (left < right) {
            for (int i = 0; i < m; i++)
                swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }
};

// link : https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked