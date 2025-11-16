// class Solution {
// public:
//     int inventoryManagement(vector<int>& stock) {
//         sort(stock.begin(),stock.end());
//         int n = stock.size();
//         return stock[n / 2];
//     }
// };

class Solution {
public:
    // 摩尔投票法
    // boyer-moore算法
    int inventoryManagement(vector<int>& stock) {
        int candidate, cnt = 0;
        for (auto e : stock) {
            if (cnt == 0)
                candidate = e;
            cnt += (candidate == e) ? 1 : -1;
        }
        return candidate;
    }
};

// link : https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/?envType=problem-list-v2&envId=XApvNy3p