// 131. 分割回文串
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    // 从当前位置开始不断地选下一个回文字符
    function<void(int)> dfs = [&](int pos) {
        if (pos == s.size()) {
            ans.emplace_back(path);
        }
        for (int i = pos; i < s.size(); i++) {
            string tmp = s.substr(pos, i - pos + 1);
            if (check(tmp)) {
                path.emplace_back(tmp);
                dfs(i + 1);
                path.pop_back();
            }
        }
    };
    dfs(0);
    return ans;
}
bool check(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}