class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& gap) {
        int n = gap.size();
        sort(gap.begin(), gap.end()); // 按左端点排序
        vector<vector<int>> ans;
        int left = gap[0][0];
        int right = gap[0][1]; // 第一个位置的右端点
        for (int i = 1; i < n; i++) {
            // 如果当前区间的左端点小于等于当前合并区间的右端点
            // 说明有重叠 更新右端点
            if (gap[i][0] <= right) {
                right = max(right, gap[i][1]); // 更新右端点
            } else {
                // 没有重叠 将当前合并区间加入结果 更新新的合并区间
                ans.push_back({left, right}); // 更新结果
                left = gap[i][0];             // 更新左右端点
                right = gap[i][1];
            }
        }
        // 将最后一个合并的区间加入结果
        ans.push_back({left, right});
        return ans;
    }
};

// 第二遍写：
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // 按左端点排升序
        vector<vector<int>> ans;
        int l = intervals[0][0];
        int r = intervals[0][1]; // 维护当前左右边界
        for (int i = 1; i < intervals.size(); i++) {
            if (r >= intervals[i][0]) { // 更新右边界
                r = max(r, intervals[i][1]);
            } else { // 更新答案 更新当前左右边界
                ans.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ans.push_back({l, r}); // 将最后一组边界push
        return ans;
    }
};

// link : https://leetcode.cn/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-100-liked