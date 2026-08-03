class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 存下每个字母最后的下标
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i)
            map[s[i]] = i;
        vector<int> ans;
        int left = 0, right = 0; // 起始和结束位置

        for (int i = 0; i < s.size(); ++i) {
            right = max(right, map[s[i]]);       // 更新当前遍历到字母的右端点
            if (right == i) {                    // 当前区间合并完毕
                ans.push_back(right - left + 1); // 更新结果
                left = right + 1;                // 更新左端点
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/partition-labels/description/?envType=study-plan-v2&envId=top-100-liked