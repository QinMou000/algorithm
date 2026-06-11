class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        dfs(candidates, output, target, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<int>& output, int target,
             int pos) {
        int sum = 0;
        for (auto e : output)
            sum += e;
        if (sum == target) {
            ans.emplace_back(output);
            return;
        } else if (sum > target || pos == candidates.size()) {
            return;
        }
        // 选择当前数字
        output.push_back(candidates[pos]);
        dfs(candidates, output, target, pos);
        output.pop_back();

        // 不选当前数字
        dfs(candidates, output, target, pos + 1);
    }
};

// link : https://leetcode.cn/problems/combination-sum/description/