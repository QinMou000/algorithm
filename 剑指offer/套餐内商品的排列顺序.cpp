class Solution {
public:
    vector<string> goodsOrder(string goods) {
        dfs(goods, 0);
        return ans;
    }

private:
    vector<string> ans;
    void dfs(string& str, int pos) {
        if (pos == str.size()) {
            ans.emplace_back(str);
            return;
        }
        // 选择 i 位置的元素作为pos位置的值
        // 并对其进行判断去重
        for (int i = pos; i < str.size(); i++) {
            bool flag = true;
            for (int j = pos; j < i; j++)
                if (str[i] == str[j])
                    flag = false;

            if (flag) { // 如果在这一层前面有重复的就直接跳过本层
                swap(str[i], str[pos]);
                dfs(str, pos + 1);
                swap(str[i], str[pos]);
            }
        }
    }
};

// link : https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/description/?envType=problem-list-v2&envId=XApvNy3p