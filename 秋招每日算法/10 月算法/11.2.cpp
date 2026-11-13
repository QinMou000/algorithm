// 61. 旋转链表

ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
        return nullptr;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        n++;
        cur = cur->next;
    }
    cur->next = head; // 串成环形链表
    int step = n - k % n;
    while (step--) {
        cur = cur->next;
    }
    ListNode *NewHead = cur->next;
    cur->next = nullptr;

    return NewHead;
}

// 3. 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> cnt;
    int n = s.size();
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        cnt[s[r]]++;
        while (cnt[s[r]] > 1) {
            cnt[s[l++]]--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// 98. 验证二叉搜索树
using LL = long long;
bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }
bool dfs(TreeNode *root, LL lower, LL upper) {
    if (!root)
        return true;
    if (root->val <= lower || root->val >= upper)
        return false;
    return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
}

// 153. 寻找旋转排序数组中的最小值
int findMin(vector<int> &nums) {
    int n = nums.size();
    int pivot = nums[n - 1];
    if (pivot > nums[0])
        return nums[0];
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > pivot) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << " " << r << endl;
    return nums[l];
}

// 695. 岛屿的最大面积
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    function<int(int, int)> dfs = [&](int i, int j) {
        if (i > m - 1 || i < 0 || j > n - 1 || j < 0 || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int area = 1;
        for (int k = 0; k < 4; k++)
            area += dfs(i + fx[k], j + fy[k]);

        return area;
    };
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    return ans;
}

// 121. 买卖股票的最佳时机
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> dp(n); // dp[i] 表示 i 位置前面最小的数
    dp[0] = prices[0];
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i - 1], prices[i - 1]);
    }
    // 这里的 dp 表就是在维护最低买入价格，由于只需要知道 i - 1 的 dp
    // 所以可以空间优化成下面的版本
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (prices[i] - dp[i] > ans)
            ans = prices[i] - dp[i];
    }
    return ans;
}
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int min_prices = INT_MAX;
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        // 不断维护最低买入价格
        if (prices[i] < min_prices)
            min_prices = prices[i];
        // 假设要在今天卖出
        if (max_profit < prices[i] - min_prices)
            max_profit = prices[i] - min_prices;
    }
    return max_profit;
}

// 394. 字符串解码
string decodeString(string s) {
    stack<pair<int, string>> stk;
    int cnt = 0;
    string ans = "";
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            cnt = cnt * 10 + c - '0';
        } else if (c >= 'a' && c <= 'z') {
            ans += c;
        } else if (c == '[') {
            stk.push(make_pair(cnt, ans));
            cnt = 0;
            ans = "";
        } else {
            string tmp = "";
            // 拿出来的是这个[]前面的那个数字
            // ans 此时为[]里面的字母
            // pair.second 为[]前面的字母
            auto pair = stk.top();
            stk.pop();
            for (int k = 0; k < pair.first; k++) {
                tmp += ans;
            }
            ans = pair.second + tmp;
        }
    }
    return ans;
}

// 236. 二叉树的最近公共祖先
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q)
        return root; // 如果root为空或者root就是p或者q直接返回
    // 在左子树中找 p 或 q
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    // 在右子树中找 p 或 q
    TreeNode *r = lowestCommonAncestor(root->right, p, q);
    // 情况1：左右都找到 → 当前 root 就是最近公共祖先
    if (l && r)
        return root;
    // 情况2：只找到一个 → 把那个往上返回
    return !l ? r : l;
}

int maxGain(vector<int> &cost, vector<int> &gain, int M) {
    int n = cost.size();
    // dp[i][j] 表示前 i 个项目，花费不超过 j 的最大收益
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            // 不选第 i 个项目
            dp[i][j] = dp[i - 1][j];
            // 选第 i 个项目
            if (j >= cost[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i - 1]] + gain[i - 1]);
            }
        }
    }
    return dp[n][M];
}