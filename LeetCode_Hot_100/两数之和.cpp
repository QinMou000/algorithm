// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target)
//                     return {i, j};
//             }
//         }
//         return {};
//     }
// };
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int tar)
    {
        int n = nums.size();
        unordered_map<int, int> hash; // 数字 和 下标 的映射
        for (int i = 0; i < n; i++)
        {
            int index = tar - nums[i]; // 计算出要在 hash 表里面找的数
            // auto it = hash.find(index);
            // if(it != hash.end())return {i , it->second};
            if (hash.count(index)) // 存在即返回 i 和 值
                return {i, hash[index]};
            else
                hash[nums[i]] = i; // 不存在则将当前的 键值插入 hash 表
        }
        return {};
    }
};

// link : https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked