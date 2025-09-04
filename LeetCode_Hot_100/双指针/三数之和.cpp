class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> ans;
        // for (int i = 0; i < n; i++)
        //     for (int j = i + 1; j < n; j++)
        //         for (int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0)
        //                 ans.push_back({nums[i], nums[j], nums[k]});
        //         }
        // return ans;

        // 三数之和：看到几数之和时要先想a+b+c=0，则-a=b+c，
        // 以这样的思路想，让b和c合到一起等于-a，这时需要对数组排序先想到双指针，
        // 双指针只有两个，如果要使用双指针有了左边的a和右边的c那么b怎么办？
        // 那么就要使b处于一个固定的阶段，即n-1，之后判断b+c是否=-a即可
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 排序
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) { // 固定一个数
            if (nums[i] > 0)          // 优化
                break;
            if (i > 0 && nums[i] == nums[i - 1]) // 去重
                continue;
            int left = i + 1, right = n - 1; // 找两个数相加等于 -nums[i]
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
                else {
                    ans.push_back({nums[left++], nums[right--], nums[i]});
                    // 去重
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked