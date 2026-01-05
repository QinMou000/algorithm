class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        unordered_map<int, int> cnt; // 水果种类与个数的映射
        for (int left = 0, right = 0; right < n; right++) {
            // 进窗口
            cnt[fruits[right]]++;
            // 判断
            while (cnt.size() > 2) {
                // 出窗口
                if (--cnt[fruits[left]] == 0)
                    cnt.erase(fruits[left]);
                left++;
            }
            // 更新结果
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/fruit-into-baskets/description/?envType=problem-list-v2&envId=sliding-window