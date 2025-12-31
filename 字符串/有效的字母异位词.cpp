class Solution {
public:
    bool isAnagram(string s, string t) {
        int vec1[30] = {0};
        int vec2[30] = {0};
        for (char c : s)
            vec1[c - 'a']++;
        for (char c : t)
            vec2[c - 'a']++;
        for (int i = 0; i < 30; i++)
            if (vec1[i] != vec2[i])
                return false;
        return true;
    }
};

// link : https://leetcode.cn/problems/valid-anagram/?envType=problem-list-v2&envId=string