class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        // output 表示当前正在构建的排列数组
        //  pos表示当前遍历到的下标
        auto dfs = [&](auto&& self, vector<int>& output, int pos) {
            if (pos == nums.size() - 1) {
                ans.push_back(output);
                return;
            }

            for (int i = pos; i < nums.size(); i++) {
                swap(nums[pos], nums[i]);
                self(self, output, pos + 1);
                swap(nums[pos], nums[i]);
            }
        };
        dfs(dfs, nums, 0);
        return ans;
    }
};

// link : https://leetcode.cn/problems/permutations/description/