// class Solution {
// public:
//     char dismantlingAction(string arr) {
//         unordered_map<char, int> cnt;
//         for (auto& c : arr)
//             cnt[c]++;
//         // 这里不要遍历哈希表,直接遍历数组才能找到第一个
//         for (auto& c : arr)
//             if (cnt[c] == 1)
//                 return c;
//         return ' ';
//     }
// };

class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<char, int> cnt;
        vector<char> key;
        for (auto& c : arr) {
            if (cnt.find(c) == cnt.end())
                key.push_back(c); // 这一步相当于给源arr数组去重
            cnt[c]++;
        }
        // 所以这里遍历key的时间复杂度就是要小于遍历arr
        for (auto& c : key)
            if (cnt[c] == 1)
                return c;
        return ' ';
    }
};

// link : https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p