#include <iostream>
#include <string>
#include <unordered_map>

// 无重复字符的最长子串
int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> cnt;
    int ans = 0;
    for (int l = 0, r = 0; r < s.size(); r++) {
        cnt[s[r]]++;
        while (cnt[s[r]] > 1) {
            cnt[s[l++]]--;
        }
        ans = std::max(ans, r - l + 1);
    }
    return ans;
}

int main() {
    std::string s1 = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s1) << std::endl;

    std::string s2 = "bbbbb";
    std::cout << lengthOfLongestSubstring(s2) << std::endl;

    std::string s3 = "pwwkew";
    std::cout << lengthOfLongestSubstring(s3) << std::endl;
}
