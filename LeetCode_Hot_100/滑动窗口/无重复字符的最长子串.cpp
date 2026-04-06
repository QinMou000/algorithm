class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[127] = {0}; // 全部 ascll 码值
        int ans = 0;
        for (int left = 0, right = 0; right < s.size(); right++) {
            // 进窗口
            int index = s[right];
            hash[index]++;
            // 判断
            while (hash[index] > 1) {
                // 出窗口
                hash[s[left++]]--;
            }
            // 更新结果
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// 第二遍写
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int ans = 0;
        for (int left = 0, right = 0; right < s.size(); right++) {
            // 入窗口
            map[s[right]]++;
            // 判断
            while (map[s[right]] > 1) {
                map[s[left++]]--;
            }
            ans = max(ans, right - left + 1);
            // 出窗口
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked