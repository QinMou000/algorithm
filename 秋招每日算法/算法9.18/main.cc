
// 525. 连续数组
int findMaxLength(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> map; // 前缀和->下标
    map[0] = -1;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i] == 0 ? -1 : 1;
        if (map.count(sum))
            ans = max(ans, i - map[sum]);
        else
            map[sum] = i;
    }
    return ans;
}

// 2472. 不重叠回文子字符串的最大数目
bool check(const string &s, int l, int r) {
    int n = s.size();
    int left = l, right = r;
    while (left < right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}
int maxPalindromes(string s, int k) {
    int ans = 0;
    int start = -1; // 记录上一组回文的末尾
    for (int r = k - 1; r < s.size(); r++) {
        int l = r - k + 1;
        if (l > start && check(s, l, r)) {
            ans++;
            start = r;
            continue;
        }
        // 要同时判断奇偶
        l = r - k;
        if (l > start && check(s, l, r)) {
            ans++;
            start = r;
        }
    }
    return ans;
}

// 1024. 视频拼接
int videoStitching(vector<vector<int>> &clips, int time) {
    vector<int> dp(time + 1, INT_MAX - 1); // 表示 [0-i) 所需片段的最小数目
    dp[0] = 0;
    for (int i = 1; i <= time; i++) {
        // [0, i) 区间
        for (auto clip : clips) {
            // 该区间可以覆盖 [0, i) 的 [0, clip[0])
            if (clip[0] < i && clip[1] >= i)
                dp[i] = min(dp[i], dp[clip[0]] + 1);
        }
    }
    return dp[time] == INT_MAX - 1 ? -1 : dp[time];
}

// 416. 分割等和子集
bool canPartition(vector<int> &nums) {
    int sum = 0, max_num = 0, n = nums.size();
    for (auto e : nums) {
        sum += e;
        max_num = max(e, max_num);
    }
    if (sum % 2 == 1)
        return false;
    if (max_num > sum / 2)
        return false;
    int target = sum / 2;
    // 在数组的前i个数中选择一些数,是否存在一种方案,使得之和恰好等于j
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j]; // 不选nums[i]
            if (j >= nums[i])        // 选择nums[i]
                dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i]];
        }
    }
    return dp[n - 1][target];
}

// 494. 目标和
int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for (auto e : nums)
        sum += e;
    int diff = sum - target; // 正整数之和 必须是偶数
    int neg = diff >> 1;     // 负整数之和
    if (diff < 0 || diff % 2 == 1)
        return 0;
    // 前 i个数中我们有dp[i][j]种方法使得和为j
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
    dp[0][0] = 1; // 前0个数中选和为0的方案数为1
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= neg; j++) {
            dp[i][j] = dp[i - 1][j]; // 不选当前数
            if (j >= nums[i - 1]) {
                // 选择当前数
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][neg];
}
// int findTargetSumWays(vector<int>& nums, int target) {
//     int cnt = 0;
//     function<void(int pos, int sum)> dfs = [&](int pos, int sum) {
//         if (pos == nums.size()) {
//             if (sum == target)
//                 cnt++;
//             return;
//         } else {
//             dfs(pos + 1, sum + nums[pos]);
//             dfs(pos + 1, sum - nums[pos]);
//         }
//     };
//     dfs(0, 0);
//     return cnt;
// }