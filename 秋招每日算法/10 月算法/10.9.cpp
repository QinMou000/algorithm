// 165. 比较版本号
int compareVersion(string version1, string version2) {
    int m = version1.size(), n = version2.size();
    int begin1 = 0, end1 = 0;
    int begin2 = 0, end2 = 0; // 左闭右开区间
    while (end1 < m || end2 < n) {
        // 用 end 找 . 作为分割
        while (end1 < m && version1[end1] != '.') {
            end1++;
        }
        while (end2 < n && version2[end2] != '.') {
            end2++;
        }
        // 转为整型
        int subV1, subV2;
        if (end1 <= m)
            subV1 = stoi(version1.substr(begin1, end1 - begin1));
        else
            subV1 = 0;
        if (end2 <= n)
            subV2 = stoi(version2.substr(begin2, end2 - begin2));
        else
            subV2 = 0;
        // 判断
        if (subV1 > subV2)
            return 1;
        if (subV1 < subV2)
            return -1;
        // 更新 begin
        begin1 = end1 + 1;
        begin2 = end2 + 1;
        end1++;
        end2++;
    }
    return 0;
}

// 337. 打家劫舍 III
// (不)选择当前节点下, 当前节点的子树被选择的最大权值和
unordered_map<TreeNode *, int> f, g;
int rob(TreeNode *root) {
    dfs(root);
    return max(f[root], g[root]);
}
void dfs(TreeNode *root) {
    if (!root)
        return;
    dfs(root->left);
    dfs(root->right);
    // 选择当前节点,但其子节点不能选择
    f[root] = g[root->left] + g[root->right] + root->val;
    // 不选择当前节点,其子节点可以选可以不选
    g[root] = max(g[root->left], f[root->left]) + max(g[root->right], f[root->right]);
}

// 91. 解码方法
// n 这个数字能不能单独映射
bool single(char n) { return (n - '0') >= 1 && (n - '0') <= 9; }
// m 和 n 能不能一起映射为一个字母
bool both(char m, char n) {
    int t = (m - '0') * 10 + n - '0';
    return t >= 10 && t <= 26;
}

int dp[105] = {0}; // 到 i 为止的解码方法总数
int numDecodings(string s) {
    int n = s.size();
    // 第一个位置单独编码
    if (single(s[0]))
        dp[0] = 1;
    // 第二个位置单独编码
    if (single(s[1]))
        dp[1] += dp[0];
    // 第一个第二个合起来编码
    if (both(s[0], s[1]))
        dp[1] += 1;

    for (int i = 2; i < n; i++) {
        // 第i个可以单独编码，那么从0到i的方法有dp[i-1]种
        if (single(s[i]))
            dp[i] += dp[i - 1];
        // 第i-1和第i位合起来可以编码，那么从0到i的方法再加上dp[i-2]种
        if (both(s[i - 1], s[i]))
            dp[i] += dp[i - 2];
    }
    return dp[n - 1];
}