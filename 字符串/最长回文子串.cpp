class Solution {
public:
    string longestPalindrome(string s) {
        // 动规
        // 中心扩展
        int ans_pos = 0;
        int ans_len = 1; // 默认一个字母也是回文串
        for (int i = 0; i < s.size() - 1; ++i) {
            // 以i为中心扩展
            int left = i, right = i; // 考虑奇数情况
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > ans_len) {
                ans_pos = left + 1;
                ans_len = right - left - 1;
            }
            left = i, right = i + 1; // 考虑偶数情况
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > ans_len) {
                ans_pos = left + 1;
                ans_len = right - left - 1;
            }
        }
        return s.substr(ans_pos, ans_len);
    }
};

// link : https://leetcode.cn/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-100-liked