class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> heap; // 数字和下标的映射
        for (int i = 0; i < k; i++)
            heap.emplace(nums[i], i);
        ans.push_back(heap.top().first);
        for (int right = k; right < n; right++)
        {
            // 进
            heap.emplace(nums[right], right);
            // 判断
            while (heap.top().second <= right - k) // 用下标控制窗口的大小
                heap.pop();                        // 出
            // cout << heap.size() << " " << heap.top().first << " "
            //      << heap.top().second << endl;
            ans.push_back(heap.top().first); // update
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/sliding-window-maximum/description/?envType=study-plan-v2&envId=top-100-liked

// 第二遍写 :
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq; // 元素和下标的映射
        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});     // 将前K个元素push进去
        ans.push_back(pq.top().first); // 更新前k个元素的最大值

        for (int right = k; right < n; right++)
        {
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