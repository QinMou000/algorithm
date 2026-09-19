
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

#include <iostream>

// 双向链表节点
template <typename T> struct Node {
    T data;
    Node *prev;
    Node *next;
    Node(const T &val) : data(val), prev(nullptr), next(nullptr) {}
};

/**
 * @brief 归并两个有序双向链表，返回合并之后新链表头
 * a、b本身已经各自有序
 */
template <typename T> Node<T> *merge(Node<T> *a, Node<T> *b) {
    if (!a)
        return b;
    if (!b)
        return a;

    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

    while (a != nullptr && b != nullptr) {
        Node<T> *sel;
        if (a->data <= b->data) {
            sel = a;
            a = a->next;
        } else {
            sel = b;
            b = b->next;
        }

        if (head == nullptr) {
            head = sel;
            tail = sel;
            sel->prev = nullptr;
        } else {
            tail->next = sel;
            sel->prev = tail;
            tail = sel;
        }
    }

    // 接上剩余节点
    if (a) {
        tail->next = a;
        a->prev = tail;
    }
    if (b) {
        tail->next = b;
        b->prev = tail;
    }
    return head;
}

/**
 * @brief 把链表从head开始，切出len个节点，返回切出来的链表头；原链表截断
 * @param head 传入链表头，函数返回后head被修改为剩下部分的头
 * @param len 需要截取多少个节点
 * @return 截取出来的子链表头
 */
template <typename T> Node<T> *split(Node<T> *&head, int len) {
    if (!head)
        return nullptr;
    Node<T> *curr = head;
    Node<T> *prev = nullptr;
    int cnt = 0;
    while (curr != nullptr && cnt < len) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    // 截断
    Node<T> *ret = head;
    if (prev != nullptr) {
        prev->next = nullptr;
    }
    head = curr; // 原链表变成剩下部分
    return ret;
}

/**
 * 非递归自底向上归并排序 双向链表
 */
template <typename T> Node<T> *list_sort(Node<T> *head) {
    if (!head || !head->next)
        return head;

    // 1.求链表总长度
    int n = 0;
    Node<T> *p = head;
    while (p) {
        n++;
        p = p->next;
    }

    Node<T> *new_head = nullptr;
    // step: 子段的长度，1,2,4,8...
    for (int step = 1; step < n; step *= 2) {
        Node<T> *curr = head;
        Node<T> *tail = nullptr;
        new_head = nullptr;

        while (curr != nullptr) {
            // 切两段：a段step长，b段step长
            Node<T> *a = split(curr, step);
            Node<T> *b = split(curr, step);

            Node<T> *merged = merge(a, b);

            // 把merged拼接到结果尾部
            if (new_head == nullptr) {
                new_head = merged;
                tail = merged;
            } else {
                tail->next = merged;
                merged->prev = tail;
            }
            // 走到合并链表的末尾
            while (tail && tail->next)
                tail = tail->next;
        }
        head = new_head;
    }
    return head;
}

// 打印链表
template <typename T> void printList(Node<T> *h) {
    for (auto p = h; p; p = p->next) {
        std::cout << p->data << " ";
    }
    std::cout << "\n";
}

int main() {
    // 构建链表 3 1 4 2
    auto n1 = new Node<int>(3);
    auto n2 = new Node<int>(1);
    auto n3 = new Node<int>(4);
    auto n4 = new Node<int>(2);
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    Node<int> *res = list_sort(n1);
    printList(res);
    return 0;
}

// 836. 矩形重叠
bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
    // 矩形 rec1 和 rec2 的水平边投影到 x 轴上的线段
    // 分别为 (rec1[0], rec1[2]) 和 (rec2[0], rec2[2])
    // 根据数学知识我们可以知道min(rec1[2], rec2[2]) > max(rec1[0],rec2[0])
    // 这两条线段有交集
    // 对于矩形 rec1 和 rec2 的竖直边投影到 y轴上的线段同理可以得到
    // 当 min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]) 时
    // 这两条线段有交集
    return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) && max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
}

// 40. 组合总和 II
vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    function<void(int, int)> dfs = [&](int pos, int sum) {
        if (sum == target) {
            ans.emplace_back(path);
            return;
        }
        if (pos == candidates.size() || sum + candidates[pos] > target)
            return;
        int offset = 1;
        while (offset + pos < candidates.size() && candidates[pos] == candidates[pos + offset])
            offset++; // 如果不选当前元素 那么后面的相同元素都要跳过
        dfs(pos + offset, sum);

        path.push_back(candidates[pos]);
        dfs(pos + 1, sum + candidates[pos]);
        path.pop_back();
    };

    dfs(0, 0);
    return ans;
}

// LCR 046. 二叉树的右视图
vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> q;
    vector<int> ans;
    if (!root)
        return ans;
    q.push(root);
    while (q.size()) {
        int size = q.size();
        while (size--) {
            TreeNode *tmp = q.front();
            q.pop();
            if (size == 0)
                ans.push_back(tmp->val);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
    return ans;
}