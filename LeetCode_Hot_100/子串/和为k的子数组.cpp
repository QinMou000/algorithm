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

// 第二遍写：
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> map; // <前缀和, 前缀和的出现次数>
        map[0] = 1;
        int pre_sum = 0; // 表示当前位置的前缀和
        for (int i = 0; i < n; i++) {
            pre_sum += nums[i];
            if (map.find(pre_sum - k) != map.end())
                ans += map[pre_sum - k]; // 计算[0,i]中有没有[j + 1,i]满足条件
            map[pre_sum]++;
        }
        return ans;
    }
};

// 假设 nums = [3, 4, 7, 2, -3, 1, 4, 2]，k = 7：
// 当遍历到第一个元素 3 时，前缀和 pre_sum = 3，此时 pre_sum - k = -4，map 中没有 -4，所以 ans 不变； 
// 当遍历到第二个元素 4 时，前缀和 pre_sum = 7，此时 pre_sum - k = 0。如果没有初始化 map[0] = 1，会认为没有符合条件的 j，但实际上
// [0,1] 这个子数组（元素 3+4）的和正好是 7，需要通过 map[0] = 1 来统计这个情况。

// link : https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked