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