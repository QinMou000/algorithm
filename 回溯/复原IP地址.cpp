class Solution {
public:
    vector<string> ans;
    int path[4];
    vector<string> restoreIpAddresses(string s) {
        string output;
        dfs(s, 0, 0, 0);
        return ans;
    }
    void dfs(string& s, int i, int j, int val) {
        if (i == s.size()) {
            if (j == 4) {
                string ret = s.substr(0, path[0]) + "." +
                             s.substr(path[0], path[1] - path[0]) + "." +
                             s.substr(path[1], path[2] - path[1]) + "." +
                             s.substr(path[2], path[3] - path[2]);
                ans.emplace_back(ret);
            }
            return;
        }
        if (j == 4)
            return;
        val = val * 10 + (s[i] - '0');
        if (val > 255) // 不合法
            return;
        // 不在当前位置断开
        if (val > 0)
            dfs(s, i + 1, j, val);
        // 在当前位置断开
        path[j] = i + 1;         // 记录断开位置
        dfs(s, i + 1, j + 1, 0); // 需要重新计算val
    }
};

// link : https://leetcode.cn/problems/restore-ip-addresses/