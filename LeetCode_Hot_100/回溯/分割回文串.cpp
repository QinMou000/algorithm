// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> output;
//         int n = s.size();

//         auto dfs = [&](this auto&& dfs, int start, int pos) {
//             if (pos == n) {
//                 ans.emplace_back(output);
//                 return;
//             }
//             // 不分割
//             if (pos < n - 1) // pos == n - 1必须进行最后一次分割
//                 dfs(start, pos + 1);
//             // 分割
//             if (check(s, start, pos)) {
//                 output.emplace_back(s.substr(start, pos - start + 1));
//                 dfs(pos + 1, pos + 1);
//                 output.pop_back(); // 恢复现场
//             }
//         };
//         dfs(0, 0);
//         return ans;
//     }
//     bool check(string str, int begin, int end) {
//         // 判断从s.[begin end]是否为回文串
//         int left = begin, right = end;
//         while (left <= right)
//             if (str[left++] != str[right--])
//                 return false;
//         return true;
//     }
// };

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int n = s.size();
        // 当前串未被分割的部分为 [pos ~ n-1]
        auto dfs = [&](this auto&& dfs, int pos) {
            if (pos == n) {
                ans.emplace_back(output);
                return;
            }
            // 遍历后面的所有字母 假设从 j位置切分 判断 [pos-j]是不是回文
            for (int j = pos; j < n; ++j) {
                if (check(s, pos, j)) { // 判断 [pos ~ j] 是不是回文串
                    output.emplace_back(s.substr(pos, j - pos + 1));
                    dfs(j + 1);        // 现在未被分割的部分为 [j+1 ~ n-1]
                    output.pop_back(); // 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
    bool check(string str, int begin, int end) {
        // 判断从s.[begin end]是否为回文串
        int left = begin, right = end;
        while (left <= right)
            if (str[left++] != str[right--])
                return false;
        return true;
    }
};

// https://leetcode.cn/problems/palindrome-partitioning/description/?envType=study-plan-v2&envId=top-100-liked

