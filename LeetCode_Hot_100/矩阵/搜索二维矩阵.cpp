// // 暴力解法 O(N * M)
// // 对每一行都进行二分查找 O(NlogM)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         for (int i = 0; i < m; i++) // 从第一行开始
//         {
//             int left = 0, right = n - 1; // 左闭右闭区间
//             while (left <= right) {
//                 int mid = left + ((right - left) >> 1);
//                 if (target == matrix[i][mid])
//                     return true;
//                 else if (target > matrix[i][mid])
//                     left = mid + 1;
//                 else
//                     right = mid - 1;
//             }
//         }
//         return false;
//     }
// };

// Z字遍历 O(M + N)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从右上角看或者从左下角看类似一个二叉搜索树
        int m = matrix.size(), n = matrix[0].size();
        // 从左下角开始二分
        int i = m - 1, j = 0;
        while (i >= 0 && j <= n - 1) { // 保证整个矩阵都在搜索范围内
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};

// link : https://leetcode.cn/problems/search-a-2d-matrix-ii/?envType=study-plan-v2&envId=top-100-liked