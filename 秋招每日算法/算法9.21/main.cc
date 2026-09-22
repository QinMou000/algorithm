// 33. 搜索旋转排序数组

int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[l] <= nums[mid]) {
            // 左边有序
            if (target >= nums[l] && target <= nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else {
            // 右边有序
            if (target >= nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

// 9. 组合总和
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    function<void(vector<int> &, int, int)> dfs = [&](vector<int> &out, int sum, int pos) {
        if (sum == target) {
            ans.emplace_back(out);
            return;
        }
        if (pos == candidates.size() || sum > target)
            return;

        // 选
        out.push_back(candidates[pos]);
        dfs(out, sum + candidates[pos], pos);
        out.pop_back();
        // 不选
        dfs(out, sum, pos + 1);
    };
    vector<int> out;
    dfs(out, 0, 0);
    return ans;
}

// 912. 排序数组
int QuickSortHelper(vector<int> &nums, int l, int r) {
    int R = l + rand() % (r - l + 1);
    swap(nums[R], nums[l]);

    int left = l, right = r;
    while (left < right) {
        // 都要找严格大于或者严格小于的元素
        while (left < right && nums[l] <= nums[right])
            right--;
        while (left < right && nums[l] >= nums[left])
            left++;
        swap(nums[left], nums[right]);
    }
    // 出循环时 left == right
    // 可以保证 left 位置的值比 l 位置的值小
    swap(nums[l], nums[left]);
    return left;
}
void QuickSort(vector<int> &nums, int l, int r) {
    if (l >= r)
        return;

    int povit = QuickSortHelper(nums, l, r);

    QuickSort(nums, l, povit - 1);
    QuickSort(nums, povit + 1, r);
}

vector<int> sortArray(vector<int> &nums) {
    QuickSort(nums, 0, nums.size() - 1);
    return nums;
}

// 124. 二叉树中的最大路径和
int ans = INT_MIN;
// 求单边最大路径
int dfs(TreeNode *root) {
    if (!root)
        return 0;
    int l = max(0, dfs(root->left));
    int r = max(0, dfs(root->right));

    ans = max(ans, l + r + root->val);

    return max(l, r) + root->val;
}
int maxPathSum(TreeNode *root) {
    dfs(root);
    return ans;
}

// 416. 分割等和子集
bool canPartition(vector<int> &nums) {
    int sum = 0, max_num = 0;
    for (auto e : nums) {
        sum += e;
        max_num = max(max_num, e);
    }
    if (sum % 2 == 1)
        return false;
    int target = sum / 2;
    if (max_num > target)
        return false;
    int n = nums.size();
    // 从前i个数里面取得的和能不能恰好等于j
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    dp[1][nums[0]] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - nums[i - 1] >= 0)
                dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i - 1]];
        }
    }
    // cout << " \t";
    // for (int j = 0; j <= target; j++)
    //     cout << j << "\t";
    // cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << i << "\t";
    //     for (int j = 0; j <= target; j++) {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    return dp[n][target];
}

// 200. 岛屿数量
void dfs(vector<vector<char>> &grid, int i, int j) {
    if (grid[i][j] == '1')
        grid[i][j] = '0';
    else
        return;
    if (i - 1 >= 0)
        dfs(grid, i - 1, j);
    if (i + 1 < grid.size())
        dfs(grid, i + 1, j);
    if (j - 1 >= 0)
        dfs(grid, i, j - 1);
    if (j + 1 < grid[0].size())
        dfs(grid, i, j + 1);
}
int numIslands(vector<vector<char>> &grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                ans++;
            }
        }
    }
    return ans;
}