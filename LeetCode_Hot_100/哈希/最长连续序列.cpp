class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int ans = 0;
        for (int num : hash) {
            // 只有当num是序列的起点时才检查（即num-1不存在）
            if (hash.find(num - 1) == hash.end()) {
                int cur = num;
                int x = 1;
                // 检查连续递增的数字
                while (hash.find(cur + 1) != hash.end()) {
                    cur++;
                    x++;
                }
                // 更新结果
                ans = max(ans, x);
            }
        }
        return ans;
    }
};