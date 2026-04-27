class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int u = 0;
        int d = m - 1;
        int l = 0;
        int r = n - 1;
        vector<int> ans;
        while (true) {
            for (int i = l; i <= r; i++) // 向右移动直到最右
                ans.push_back(matrix[u][i]);
            if (++u > d) // 重新设定上边界 若上边界大于下边界 则遍历遍历完成
                break;
            for (int i = u; i <= d; i++) // 向下
                ans.push_back(matrix[i][r]);
            if (--r < l) // 重新设定右边界
                break;
            for (int i = r; i >= l; i--) // 向左
                ans.push_back(matrix[d][i]);
            if (--d < u) // 重新设定下边界
                break;
            for (int i = d; i >= u; i--) // 向上
                ans.push_back(matrix[i][l]);
            if (++l > r) // 重新设定左边界
                break;
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/spiral-matrix/?envType=study-plan-v2&envId=top-100-liked