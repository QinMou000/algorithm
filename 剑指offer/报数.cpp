// class Solution {
// public:
//     vector<int> countNumbers(int cnt) {
//         vector<int> ans;
//         auto check = [&](int i) {
//             int count = cnt;
//             while (i) {
//                 i /= 10;
//                 count--;
//             }
//             return count >= 0;
//         };
//         for (int i = 1;; i++) {
//             if (check(i))
//                 ans.push_back(i);
//             else
//                 break;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> countNumbers(int cnt) {
        vector<int> ans;
        int max = pow(10, cnt); 
        int i = 1;
        while (i < max)
            ans.push_back(i++);
        return ans;
    }
};

// TODO 对于大数的解决方案
// link : https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/?envType=problem-list-v2&envId=XApvNy3p