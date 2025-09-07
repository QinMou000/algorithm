// 滑动窗口通常适用于非负的情况
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0, sum = 0;
//         for (int left = 0, right = 0; right < n; right++) {
//             // 进窗口
//             sum += nums[right];
//             cout << "left: " << left << " right: " << right << " sum: " <<
//             sum
//                  << endl;
//             while (left < right && sum > k) {
//                 // 出窗口
//                 sum -= nums[left++];
//             }
//             // 判断
//             if (sum == k) {
//                 // update
//                 ans++;
//                 cout << "sum == k " << " left: " << left << " right: " <<
//                 right
//                      << " sum: " << sum << endl;
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    const int N = 2e4 + 10;
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int prev_sum = 0;             // 表示当前位置及之前位置的和
        unordered_map<int, int> hash; // 统计前缀和出现的次数 <前缀和, 出现次数>
        hash[0] = 1;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            prev_sum += nums[j]; // 计算当前位置的前缀和
            if (hash.find(prev_sum - k) != hash.end())
            {
                // 寻找在当前位置之前有多少个前缀和为sum - k
                ans += hash[prev_sum - k];
            }
            hash[prev_sum]++; // 更新前缀和为sum的次数
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked