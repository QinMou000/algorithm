class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int ans = 0;
        for (int num : hash) {
            // 只有当num是序列的起点时才检查（即num-1不存在）
            if (hash.find(num - 1) == hash.end()) {
                int cur = num;
                int x = 1;
                // 检查连续递增的数字
                while (hash.find(cur + 1) != hash.end()) {
                    cur++;
                    x++;
                }
                // 更新结果
                ans = max(ans, x);
            }
        }
        return ans;
    }
};

// 第二遍写:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map{nums.begin(), nums.end()}; // 主要是为了去重
        int ans = 0;
        for (auto& e : map) {
            // 也就是 e - 1 在 map 里面找不到
            if (map.find(e - 1) == map.end()) {
                // 这个时候我们把 e 看作整个连续序列的开头
                int cnt = 0, i = e; // 从 i 开始计算
                while (map.find(i++) != map.end()) {
                    // 如果找到i了就把cnt++;
                    cnt++;
                }
                // 取最大值
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked