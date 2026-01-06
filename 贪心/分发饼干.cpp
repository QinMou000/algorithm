class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, i = 0, j = 0;
        int m = g.size(), n = s.size();
        while (i < m && j < n) {
            if (s[j] >= g[i]) {
                ans++;
                i++, j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/assign-cookies/?envType=problem-list-v2&envId=greedy