// class Solution {
// public:
//     vector<vector<int>> fileCombination(int target) {
//         vector<vector<int>> ans;
//         vector<int> res;
//         for (int i = 1; i < target; i++) { // 从 i 开始算
//             int sum = 0;
//             res.clear();
//             for (int j = i; sum < target; j++) {
//                 sum += j;
//                 res.push_back(j);
//                 if (sum == target)
//                     ans.push_back(res);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int Summation(int left, int right) {
        return ((left + right) * (right - left + 1)) / 2; // 等差数列求和公式
    }

    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int left = 1, right = 2; // 注意起始值
        while (left < right) {
            if (Summation(left, right) > target)
                left++; // 说明以left为起点不存在一个数列满足要求
                        // 直接以下一个数为起点重新来
            else if (Summation(left, right) < target)
                right++; // 说明当前 left right包含的数太小
            else {
                for (int i = left; i <= right; i++)
                    res.emplace_back(i);
                ans.emplace_back(res);
                res.clear(); // 注意清除已经添加到最终答案的数组
                left++;      // 继续以下一个数为起点开始判断
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/description/?envType=problem-list-v2&envId=XApvNy3p