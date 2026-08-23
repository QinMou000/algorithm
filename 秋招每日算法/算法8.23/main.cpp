#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // 435. 无重叠区间
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();
        // 按照左端点排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> x, const vector<int> y) { return x[0] < y[0]; });

        int r = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (r > intervals[i][0]) {
                r = min(r, intervals[i][1]); // 删掉右端点较大的区间
                ans++;
            } else
                r = intervals[i][1];
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
