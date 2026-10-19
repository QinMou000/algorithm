#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 会议室 II
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &interval : intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << sol.minMeetingRooms(intervals1) << endl; // expect 2

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << sol.minMeetingRooms(intervals2) << endl; // expect 1

    vector<vector<int>> intervals3 = {};
    cout << sol.minMeetingRooms(intervals3) << endl; // expect 0
    return 0;
}
