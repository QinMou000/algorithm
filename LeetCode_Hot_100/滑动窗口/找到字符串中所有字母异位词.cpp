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

// link : https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked