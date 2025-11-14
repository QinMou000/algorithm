class Solution {
public:
    vector<int> trainingPlan(vector<int>& act) {
        int n = act.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && act[left] % 2 == 1) // 找偶数放到右边
                left++;
            while (left < right && act[right] % 2 == 0) // 找奇数放到左边
                right--;
            swap(act[left], act[right]);
        }
        return act;
    }
};

// link : https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/description/?envType=problem-list-v2&envId=XApvNy3p

// class Solution {
// public:
//     vector<int> trainingPlan(vector<int>& act) {
//         // right 的位置是偶数 left 的位置是奇数
//         int n = act.size();
//         vector<int> tmp(n);
//         int left = 0, right = n - 1;
//         for (auto e : act) {
//             if (e % 2 == 1) // 奇数
//                 tmp[left++] = e;
//             if (e % 2 == 0) // 偶数
//                 tmp[right--] = e;
//         }
//         return tmp;
//     }
// };

// class Solution {
// public:
//     vector<int> trainingPlan(vector<int>& act) {
//         int n = act.size();
//         vector<int> tmp(n);
//         int index = 0;
//         for (int i = 0; i < n; i++) {
//             if (act[i] % 2 != 0) // 奇数
//                 tmp[index++] = act[i];
//         }
//         for (int i = 0; i < act.size(); i++) {
//             if (act[i] % 2 == 0) // 偶数
//                 tmp[index++] = act[i];
//         }
//         return tmp;
//     }
// };