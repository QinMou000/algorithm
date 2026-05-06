class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int num = nums[i];        // 遍历到该元素了
            int index = abs(num) - 1; // 该元素对应的下标 该元素可能为负
            if (nums[index] > 0) {    // 该元素未被访问过
                nums[index] = -nums[index];
            } else {
                ans.push_back(index + 1);
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/