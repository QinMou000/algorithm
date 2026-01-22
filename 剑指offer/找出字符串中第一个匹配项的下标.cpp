// class Solution {
// public:
//     //  第一次写 这个代码好丑陋
//     int strStr(string str, string s) {
//         int n = str.size();
//         int m = s.size();
//         if (n < m)
//             return -1;
//         for (int i = 0; i < n; i++) {
//             if (str[i] == s[0]) {
//                 int index = 0;    // 给s用的下标
//                 bool flag = true; // 先假设这个i就是答案
//                 for (int j = i; j < n && index < m; j++) {
//                     cout << str[j] << " " << s[index] << endl;
//                     if (str[j] != s[index++]) {
//                         flag = false;
//                     }
//                 }
//                 if (index == m && flag)
//                     return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int strStr(string str, string s) {
        int n = str.size(), m = s.size();
        for (int i = 0; i <= n - m; i++) {
            int j = i, k = 0; // j是str使用的下标 k是s使用的下标
            while (k < m && str[j] == s[k]) {
                j++;
                k++;
            }
            if (k == m)
                return i;
        }
        return -1;
    }
};
// KMP算法 TODO

// link : https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150