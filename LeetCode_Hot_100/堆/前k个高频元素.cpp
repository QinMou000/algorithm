class Solution {
public:
    // 用堆解决
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 数字和出现次数的映射
        unordered_map<int, int> map;
        for (auto e : nums)
            map[e]++;
        auto com = [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.second > y.second; // 用 second 做比较 小顶堆
        };
        // 自定义比较函数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(com)>
            pir_q;
        for (auto kv : map) {
            pir_q.push(kv); // 将 kv push 进优先级队列
            // 因为我们只要前k个 如果当前堆大小大于等于k就pop
            if (pir_q.size() > k)
                pir_q.pop(); // 因为是小顶堆 所以pop掉的都是较小值
        }
        vector<int> ans;
        while (!pir_q.empty()) { // 堆里面的k个元素就是答案
            ans.push_back(pir_q.top().first);
            pir_q.pop();
        }
        return ans;
    }

    // 用排序解决
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     // 数字和出现次数的映射
    //     unordered_map<int, int> map;
    //     for (auto e : nums)
    //         map[e]++;
    //     vector<pair<int, int>> arr;
    //     for (auto kv : map)
    //         arr.push_back(kv);
    //     auto com = [](const pair<int, int> x, const pair<int, int> y) {
    //         return x.second > y.second; // 用 second 做比较
    //     };
    //     sort(arr.begin(), arr.end(), com); // 自定义比较函数
    //     vector<int> ans;
    //     for (int i = 0; i < k; i++)
    //         ans.push_back(arr[i].first);
    //     return ans;
    // }
};

// link : https://leetcode.cn/problems/top-k-frequent-elements/?envType=study-plan-v2&envId=top-100-liked