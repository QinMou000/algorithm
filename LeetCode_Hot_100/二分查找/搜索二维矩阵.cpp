class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // 用 lambda 表达式封装二维数组折叠为一维数组的核心逻辑
        auto RowIndex = [&](int mid) { return mid / n; };
        auto ColIndex = [&](int mid) { return mid % n; };
        // 用二分在折叠后的一维数组查找结果
        // 左闭右闭区间
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midNum = matrix[RowIndex(mid)][ColIndex(mid)];
            if (midNum == target)
                return true;
            else if (midNum > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
// 其实这道题从 左上角看也是一个二叉搜索树 有没有想起什么?
// link : https://leetcode.cn/problems/search-a-2d-matrix-ii/


// link : https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked