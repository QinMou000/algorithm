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

// 第三遍写：

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set{nums.begin(), nums.end()};
        int ans = 0;
        for (auto& e : set) { // 这里遍历去重之后的set会好一些（我是小丑）
            if (set.find(e - 1) == set.end()) {
                // hash里面没找到e - 1 把当前数作为序列开头
                int cnt = 0, cur = e;
                while (set.find(cur++) != set.end()) {
                    // 在hash里面能找到下一个数
                    cnt++;
                }
                ans = max(ans, cnt);
                // 神来之笔 优化如果当前的链大于整个hash的一半，那就不可能还有另外一个答案
                // 如果有，那么总和就超过了整个set的大小
                if (ans > set.size() / 2)
                    break;
            }
        }
        return ans;
    }
};

// 第四遍写：

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!set.count(nums[i] - 1)) {
                // nums[i]是一个新连续序列的开头
                int cur = nums[i], ret = 0;

                while (set.count(cur)) {
                    cur++, ret++;
                }
                ans = max(ans, ret);
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked