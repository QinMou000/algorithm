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

// link : https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked