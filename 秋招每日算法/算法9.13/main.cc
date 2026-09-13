#include <bits/stdc++.h>
using namespace std;

// 题目：一个环上有 0～9 共 10 个点，从 0 出发，每一步可以顺时针或者逆时针走一个点，求走 N 步之后重新回到 0
// 一共有多少种不同走法。 输入约定：标准输入读取一个整数 n；输出约定：标准输出打印方案数。
long long countReturnWays([[maybe_unused]] int n) {
    vector<vector<int>> dp(n + 1, vector<int>(10)); // dp[i][j] 表示走 i 步回到 j 的方案数
    dp[0][0] = 1;                                   // 走 0 步回到 0 的方案数为 1
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = dp[i - 1][(j + 1) % 10] + dp[i - 1][(j + 9) % 10]; // 顺时针走一步或者逆时针走一步
        }
    }
    return dp[n][0];
    return 0;
}

struct TestCase {
    int n;
    long long expected;
};

bool runLocalTests() {
    // 这些用例覆盖零步、奇数步、短偶数步、绕环相关步数和稍大规模。
    const vector<TestCase> tests = {
        {0, 1}, {1, 0}, {2, 2}, {3, 0}, {4, 6}, {5, 0}, {6, 20}, {8, 70}, {10, 254}, {12, 948}, {20, 215766},
    };

    bool ok = true;
    for (const auto &tc : tests) {
        const long long got = countReturnWays(tc.n);
        if (got != tc.expected) {
            cerr << "用例失败：n=" << tc.n << "，期望=" << tc.expected << "，实际=" << got << '\n';
            ok = false;
        }
    }

    if (ok) {
        cerr << "全部测试通过，共 " << tests.size() << " 个用例。\n";
    }
    return ok;
}

// #define RUN_LOCAL_TESTS

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef RUN_LOCAL_TESTS
    return runLocalTests() ? 0 : 1;
#else
    int n = 0;
    if (!(cin >> n)) {
        return 0;
    }

    cout << countReturnWays(n) << '\n';
    return 0;
#endif
}

// 207. 课程表
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, vector<int>> edges; // 邻接表
    vector<int> in(numCourses);            // 入度表

    for (auto P : prerequisites) {
        edges[P[1]].push_back(P[0]); // P[1] -> P[0]
        in[P[0]]++;                  // P[0]的入度加一
    }

    queue<int> q; // 队列
    for (int i = 0; i < numCourses; i++) {
        if (in[i] == 0) // 入度为零 入队列
            q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (auto e : edges[t]) { // 把从t出去的结点的入度--
            in[e]--;
            if (in[e] == 0) // 入度为零的结点再次入队列
                q.push(e);
        }
    }
    // 判断是否有剩下的结点
    for (auto e : in) {
        if (e != 0) // 还有入度不为零的结点 那么就有环
            return false;
    }
    return true;
}

// 78. 子集
vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    auto dfs = [&](this auto &&dfs, vector<int> output, int pos) {
        if (pos == nums.size()) {
            ans.push_back(output);
            return;
        }
        // 不选当前位置
        dfs(output, pos + 1);
        // 选当前位置
        output.push_back(nums[pos]);
        dfs(output, pos + 1);
        output.pop_back(); // 恢复现场
    };
    vector<int> output;
    dfs(output, 0);
    return ans;
}

// 16. 最接近的三数之和
int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int div = INT_MAX;
    int ans;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) < div) {
                div = abs(sum - target);
                ans = sum;
            }
            if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    return ans;
}