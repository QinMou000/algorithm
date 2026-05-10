class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // 排序后的词和排序前的词的映射
        unordered_map<string, vector<string>> map;
        for (auto& str : strs) {
            string raw_str = str;
            sort(str.begin(), str.end());
            map[str].push_back(raw_str);
        }
        for (auto it : map) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

// 第二遍写
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for (auto str : strs) {
            string tmp = str;
            sort(str.begin(), str.end());
            if (map.find(str) == map.end()) {
                map[str];
            }
            map[str].push_back(tmp);
        }
        for (auto arr : map) {
            ans.push_back(arr.second);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/group-anagrams/description/?envType=problem-list-v2&envId=hash-table