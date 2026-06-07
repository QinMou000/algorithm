class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + (m * n) <= ls; i++) {
            unordered_map<string, int> map; // 单词,出现次数
            // 第一个窗口，看看s被窗口框到的有哪些单词，哈希表对应单词的数量++，
            // 这两个for主要是用来初始化滑动窗口，现在只是框住了，还没开始滑
            for (int j = 0; j < m; j++)
                ++map[s.substr(i + j * n, n)];
            // 遍历words，哈希表对应单词数量--，对应单词数量为0时删除单词
            for (auto& str : words)
                if (--map[str] == 0)
                    map.erase(str);

            for (int begin = i; begin < ls - m * n + 1; begin += n) {
                // 第一个窗口已经加减过了，所以start==i的时候直接到下面去判断满不满足就行了
                if (begin != i) {
                    // 右侧的新进入窗口的单词，要++
                    string right_word = s.substr(begin + (m - 1) * n, n);
                    if (++map[right_word] == 0)
                        map.erase(right_word);
                    // 左侧离开的单词，要--
                    string left_word = s.substr(begin - n, n);
                    if (--map[left_word] == 0)
                        map.erase(left_word);
                }
                // 判断哈希表是否为空，如果是，条件符合，窗口起始下标放进结果集
                if (map.empty())
                    ans.push_back(begin);
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/substring-with-concatenation-of-all-words/