class Solution {
public:
    vector<int> maxAltitude(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n)
            return {};
        vector<int> ans;
        priority_queue<pair<int, int>> pq; // 元素和下标的映射
        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});     // 将前K个元素push进去
        ans.push_back(pq.top().first); // 更新前k个元素的最大值

        for (int right = k; right < n; right++) {
            // 进窗口
            pq.push({nums[right], right});
            // 判断
            // 只需要判断最大的元素下标是否不在范围即可
            while (pq.top().second <= right - k)
                pq.pop();
            ans.push_back(pq.top().first); // 更新结果
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p