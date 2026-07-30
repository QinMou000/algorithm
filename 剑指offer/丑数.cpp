class Solution {
  public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        unordered_set<long long> hash;
        q.push(1);
        int cnt = 0;
        while (!q.empty()) {
            long long tmp = q.top();
            q.pop();
            cnt++;
            cout << cnt << " " << tmp << endl;
            if (cnt == n)
                return tmp;
            if (!hash.count(tmp * 2)) {
                q.push(tmp * 2);
                hash.insert(tmp * 2);
            }
            if (!hash.count(tmp * 3)) {
                q.push(tmp * 3);
                hash.insert(tmp * 3);
            }
            if (!hash.count(tmp * 5)) {
                q.push(tmp * 5);
                hash.insert(tmp * 5);
            }
        }
        return -1;
    }
};

// link : https://leetcode.cn/problems/ugly-number-ii/description/