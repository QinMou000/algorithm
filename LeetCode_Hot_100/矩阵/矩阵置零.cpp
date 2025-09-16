// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<bool> row(m, false), col(n, false); // 标记数组
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (matrix[i][j] == 0) {
//                     row[i] = true; // 标记行
//                     col[j] = true; // 标记列
//                 }
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (row[i] == true || col[j] == true)
//                     matrix[i][j] = 0; // 根据标记数组对原数组进行修改
//     }
//     // 时间复杂度：O(mn)
//     // 空间复杂度：O(m+n)
// };

// 还有一种方法是 用矩阵的第一行和第一列作为标记数组
// 但这会影响第一行第一列的判断 所以我们先用两个变量标记第一行第一列是否出现了零
// 之后在完成后面的工作后 再对第一行第一列进行修改
// 这样可以把空间复杂度降低到 O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row = false, col = false;
        // 根据第一行第一列有没有零 初始化两个标记变量
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                row = true;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                col = true;
        }
        // 将第一行第一列当作 标记数组 初始化
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0; // 根据标记数组对原数组进行修改

        // 对第一行第一列进行处理
        if (row)
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        if (col)
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
    }
    // 时间复杂度：O(mn)
    // 空间复杂度：O(1)
};

// link : https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked