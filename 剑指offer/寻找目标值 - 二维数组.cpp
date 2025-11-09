class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        int m = plants.size();
        if (m == 0)
            return false;
        int n = plants[0].size();
        int i = 0, j = n - 1; // 右上角 开始二分
        while (i < m && j >= 0) {
            if (plants[i][j] == target)
                return true;
            else if (plants[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};

// link : https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/description/?envType=problem-list-v2&envId=XApvNy3p

// 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/