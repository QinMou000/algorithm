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

// 394. 字符串解码
string decodeString(string s) {
    // [ 把当前倍数、当前已经攒好的字符串压栈 清空 res 和 time
    // 用来收集括号内部字符
    // ] 弹出栈 把括号内收集到的res重复倍数次
    // 拼回旧字符串 赋值给 res
    int times = 0;
    string res = "";
    stack<pair<string, int>> stk; // res,times
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            times = times * 10 + c - '0';
        } else if (c >= 'a' && c <= 'z') {
            res += c;
        } else if (c == '[') {
            stk.push(make_pair(res, times));
            res = "";
            times = 0;
        } else if (c == ']') {
            string tmp;
            auto Pair = stk.top();
            stk.pop();
            for (int i = 0; i < Pair.second; i++) {
                tmp += res;
            }
            res = Pair.first + tmp;
        }
    }
    return res;
}

// 46. 全排列
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    function<void(int pos, vector<int> out)> dfs = [&](int pos, vector<int> out) {
        if (pos == nums.size() - 1) {
            ans.emplace_back(out);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(out[pos], out[i]);
            dfs(pos + 1, out);
            swap(out[pos], out[i]);
        }
    };
    dfs(0, nums);
    return ans;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 23. 合并 K 个升序链表
ListNode *Merge(ListNode *l1, ListNode *l2) {
    ListNode *dump = new ListNode(-1);
    ListNode *cur = dump;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1)
        cur->next = l1;
    if (l2)
        cur->next = l2;
    return dump->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = nullptr;
    for (auto list : lists) {
        head = Merge(head, list);
    }
    return head;
}

// 8. 字符串转换整数 (atoi)
int myAtoi(string s) {
    int i = 0;
    int n = s.size();
    while (i < n) {
        if (s[i] == ' ')
            i++;
        else
            break;
    }

    int flag = 1;
    if (s[i] == '-') {
        flag = -1;
        i++;
    } else if (s[i] == '+')
        i++;

    long long ans = 0;
    while (i < n) {
        if (s[i] < '0' || s[i] > '9')
            break;
        ans = ans * 10 + s[i] - '0';
        if (flag == 1 && ans > INT_MAX)
            return INT_MAX;
        if (flag == -1 && ans > (long long)INT_MAX + 1)
            return INT_MIN;
        i++;
    }
    return ans * flag;
}

// 142. 环形链表 II
ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
}

// 398. 随机数索引
class Solution {
  public:
    unordered_map<int, vector<int>> map;
    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> res = map[target];
        return res[rand() % res.size()];
    }
};

// 150. 逆波兰表达式求值
int evalRPN(vector<string> &tokens) {
    stack<int> stk;

    for (auto token : tokens) {
        char c = token[0];
        if (token.size() > 1 || isdigit(c)) {
            stk.push(stoi(token));
            continue;
        }
        int x = stk.top();
        stk.pop();
        if (c == '+')
            stk.top() += x;
        if (c == '-')
            stk.top() -= x;
        if (c == '*')
            stk.top() *= x;
        if (c == '/')
            stk.top() /= x;
    }
    return stk.top();
}

// 逆波兰表达式 → 中缀表达式（会自动补括号保证优先级正确）
string rpnToInfix(vector<string> &tokens) {
    stack<string> stk;
    for (auto &token : tokens) {
        // 数字：直接压入字符串
        if (token.size() > 1 || isdigit(token[0])) {
            stk.push(token);
            continue;
        }
        // 运算符：弹出右操作数b，再弹出左操作数a
        string b = stk.top();
        stk.pop();
        string a = stk.top();
        stk.pop();
        // 包裹括号，规避运算符优先级错误
        string expr = "(" + a + token + b + ")";
        stk.push(expr);
    }
    return stk.top();
}

// 获取运算符优先级
int priority(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // '('
}

vector<string> infixToRPN(const string &s) {
    vector<string> output;
    stack<char> opStk;
    int n = s.size();
    int i = 0;
    while (i < n) {
        char ch = s[i];
        if (isdigit(ch)) {
            // 处理多位数
            int j = i;
            while (j < n && isdigit(s[j]))
                j++;
            output.push_back(s.substr(i, j - i));
            i = j;
        } else if (ch == '(') {
            opStk.push(ch);
            i++;
        } else if (ch == ')') {
            while (opStk.top() != '(') {
                output.push_back(string(1, opStk.top()));
                opStk.pop();
            }
            opStk.pop(); // 弹出'('丢弃
            i++;
        } else {
            // +-*/ 运算符
            while (!opStk.empty() && priority(opStk.top()) >= priority(ch)) {
                output.push_back(string(1, opStk.top()));
                opStk.pop();
            }
            opStk.push(ch);
            i++;
        }
    }
    // 剩余运算符全部输出
    while (!opStk.empty()) {
        output.push_back(string(1, opStk.top()));
        opStk.pop();
    }
    return output;
}

// 70. 爬楼梯
int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    if (n < 2)
        return dp[1];
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 377. 组合总和 Ⅳ
int combinationSum4(vector<int> &nums, int target) {
    int n = nums.size();
    vector<long long> dp(target + 1, 0); // 和为 i 的方案有 dp[i] 个
    dp[0] = 1;                           // 和为0的方案有一个 就是什么都不选
    for (int i = 1; i <= target; i++) {
        for (auto e : nums) {
            if (i - e >= 0 && dp[i - e] + dp[i] <= INT_MAX)
                dp[i] += dp[i - e];
        }
    }
    return dp[target];
}

// 452. 用最少数量的箭引爆气球
int findMinArrowShots(vector<vector<int>> &points) {
    int n = points.size();
    int ans = 0;
    sort(points.begin(), points.end(), [](const vector<int> &v1, const vector<int> &v2) { return v1[1] < v2[1]; });
    int shot = points[0][1]; // 第一支箭

    for (auto ball : points) {
        if (ball[0] > shot) { // 左端点小于箭坐标 说明覆盖不了
            ans++;
            shot = ball[1];
        }
    }
    return ans + 1;
}

// 139. 单词拆分
bool wordBreak(string s, vector<string> &wordDict) {
    unordered_map<string, int> cnt;
    for (auto &s : wordDict) {
        cnt[s]++;
    }
    int n = s.size();
    vector<bool> dp(n + 1); // 字符串中 0-i （不）可以被dict中的拼接
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        // j 为单词的起始位置
        for (int j = 0; j < i; j++) {
            dp[i] = dp[j] & cnt.count(s.substr(j, i - j));
            if (dp[i] == true)
                break; // 可以拼接 无需后续判断
        }
    }
    return dp[n];
}

// 96. 不同的二叉搜索树

// int numTrees(int n) {
//     long long ans = 1;
//     for (int i = 0; i < n; i++) {
//         ans = ans * 2 * (2 * i + 1) / (i + 2);
//     }
//     return (int)ans;
// }
int numTrees(int n) {
    /*
    dp[i] = i个不同的数组成的二叉搜索数的个数
    假设 i = 5
    当根节点等于 1 时 ，其余数字都比1大，只能在右边
    dp[i] += dp[4]
    当根节点等于 2 时，左边有一个1比2小，右边有三个比2大的数字
    dp[i] += dp[1] * dp[3]
    当根节点等于 3时，左边有两个数比3小，右边有两个数比3大的数字
    dp[i] += dp[2] * dp[2]
    知道根节点等于5，左边有4个数字比5小，只能放在5的左边
    dp[i] += dp[4]
     */
    vector<int> dp(n + 1);
    dp[0] = 1; // 空结构也算一种情况
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int l = dp[j - 1];
            int r = dp[i - j];
            dp[i] += l * r;
        }
    }
    return dp[n];
}