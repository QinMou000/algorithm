class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto& e : stones)
            pq.push(e);
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x > y) {
                pq.push(x - y);
            } else if (x < y) {
                pq.push(y - x);
            }
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};

// link : https://leetcode.cn/problems/last-stone-weight/