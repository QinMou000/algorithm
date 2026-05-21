// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs.size();
//         // 按字典序排序
//         sort(strs.begin(), strs.end());
//         string begin_str = strs[0];
//         string end_str = strs[n - 1];
//         string ans = "";
//         for (int i = 0, j = 0; i < begin_str.size() && j < end_str.size();) {
//             if (begin_str[i] == end_str[j]) {
//                 ans += begin_str[i];
//                 i++, j++;
//             } else
//                 break;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int c_len = INT_MAX;
        // 求出最小的单词长度
        for (int k = 0; k < strs.size(); k++)
            c_len = c_len < strs[k].size() ? c_len : strs[k].size();
        for (int j = 0; j < c_len; j++) { // 字符的下标
            char c;
            bool is_euqal = true;
            for (int i = 1; i < strs.size(); i++) { // 数组的下标
                cout << strs[i][j] << strs[i - 1][j] << endl;
                if (strs[i][j] != strs[i - 1][j])
                    is_euqal = false;
            }
            if (is_euqal)
                ans += strs[0][j];
            else
                break;
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/longest-common-prefix/description/