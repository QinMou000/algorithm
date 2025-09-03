class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 互相为字母异位词的 排序后相同
        vector<vector<string>> ans;
        // 将排序后的字符串作为键 排序前的字符串储存到值(vector<string>)里面
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end()); // 排序
            hash[key].push_back(strs[i]); // 将源字符存到值中
        }
        for (auto e : hash)
            ans.push_back(e.second); // 统一按顺序插入
        return ans;
    }
};
// link : https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked