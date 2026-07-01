class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        vector<int> p_cnt(26);
        vector<int> s_cnt(26);
        for (auto c : p)
            p_cnt[c - 'a']++; // 统计
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            s_cnt[s[right] - 'a']++;         // 进窗口
            if (right - left + 1 > p.size()) // 判断
                s_cnt[s[left++] - 'a']--;    // 出窗口
            if (p_cnt == s_cnt)
                ans.push_back(left); // 更新结果
        }
        return ans;
    }
};

// 第二遍写
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_map(30);
        vector<int> s_map(30);
        for (char c : p)
            p_map[c - 'a']++;
        vector<int> ans;
        for (int left = 0, right = 0; right < s.size(); right++) {
            // 入窗口
            s_map[s[right] - 'a']++;
            // 判断
            if (p.size() < right - left + 1)
                s_map[s[left++] - 'a']--; // 出窗口
            // 更新
            if (s_map == p_map)
                ans.push_back(left);
        }
        return ans;
    }
};

// 第三遍写：
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnt1;
        unordered_map<char, int> cnt2;
        for (char c : p)
            cnt2[c]++;
        vector<int> ans;

        for (int left = 0, right = 0; right < s.size(); right++) {
            // 入窗口
            cnt1[s[right]]++;
            // 判断
            while (right - left + 1 > p.size()) {
                // 出窗口
                if (--cnt1[s[left]] == 0)
                    cnt1.erase(s[left]); // 因为是哈希表，需要删除
                left++;
            }
            // 更新结果
            if (cnt1 == cnt2)
                ans.push_back(left);
        }
        return ans;
    }
};

// 第四遍写：
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;
        vector<int> ans;
        for (auto c : p)
            hash1[c]++;

        for (int left = 0, right = 0; right < s.size(); right++) {
            char c = s[right];
            hash2[c]++;                            // 入窗口
            if (hash1.size() < right - left + 1) { // 判断
                char del = s[left++];              // 出窗口
                if (--hash2[del] == 0)             // 需要删除对应的节点
                    hash2.erase(del);
            }
            if (hash1 == hash2) // 更新结果
                ans.push_back(left);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked