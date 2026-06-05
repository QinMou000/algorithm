class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        dfs(nums, output, 0);
        return ans;
    }
    // pos当前位置选 or 不选
    // nums 原数组
    // output 当前搜索到的数组
    void dfs(vector<int>& nums, vector<int>& output, int pos) {
        if (pos == nums.size()) {
            // 无论output里面有几个元素 都把nums搜索完了
            ans.emplace_back(output);
            return;
        }

        // 选pos
        output.push_back(nums[pos]);
        dfs(nums, output, pos + 1);
        // 恢复现场
        output.pop_back();

        // 不选pos
        dfs(nums, output, pos + 1);
    }
};

// link : https://leetcode.cn/problems/subsets/description/?envType=study-plan-v2&envId=top-100-liked