#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 300. 最长递增子序列
int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    // 以i结尾的最长子序列长度
    vector<int> dp(n, 1); // 都要初始化为1

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

// 93. 复原 IP 地址
vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    function<bool(int i, int j)> check = [&](int i, int j) {
        if (j - i > 3 || (j - i > 1 && s[i] == '0'))
            return false;
        return stoi(s.substr(i, j - i)) <= 255;
    };
    int n = s.size();
    for (int i = 1; i < n && check(0, i); i++) {
        for (int j = i + 1; j < n && check(i, j); j++) {
            for (int k = j + 1; k < n && check(j, k); k++) {
                if (check(k, n)) {
                    ans.emplace_back(
                        s.substr(0, i) + '.' + s.substr(i, j - i) + '.' +
                        s.substr(j, k - j) + '.' + s.substr(k, n - k));
                }
            }
        }
    }
    return ans;
}

// 32. 最长有效括号
int longestValidParentheses(string s) {
    stack<int> stk; // 存下标
    stk.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') // 左括号
            stk.push(i);
        else {
            // 右括号
            stk.pop();
            if (stk.empty()) {
                // 栈为空 把新边界入栈
                stk.push(i);
            } else {
                // 栈不为空 更新结果
                ans = max(ans, i - stk.top());
            }
        }
    }
    return ans;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {
    }
};

// 437. 路径总和 III
// 以root为根 找向下路径和
int dfs(TreeNode *root, int targetSum) {
    if (!root)
        return 0;
    if (targetSum == root->val)
        return 1;

    return dfs(root->left, targetSum - root->val) +
           dfs(root->right, targetSum - root->val);
}

int pathSum(TreeNode *root, int targetSum) {
    if (!root)
        return 0;
    int ret = dfs(root, targetSum);

    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
}

// 31. 下一个排列
void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;
    // 找第一个升序序列 较小数
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
    // 找i后面的较大数
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

// 143. 重排链表
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

ListNode *divide(ListNode *head) {
    if (!head)
        return nullptr;
    ListNode *dump = new ListNode(-1, head);
    ListNode *fast = dump;
    ListNode *slow = dump;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    delete dump;
    return slow;
}

ListNode *reverse(ListNode *head) {
    if (!head)
        return nullptr;
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next = head->next;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void MergeList(ListNode *h1, ListNode *h2) {
    while (h1 && h2) {
        ListNode *h1Next = h1->next;
        h1->next = h2;
        ListNode *h2Next = h2->next;
        h2->next = h1Next;
        h1 = h1Next;
        h2 = h2Next;
    }
}

void reorderList(ListNode *head) {
    ListNode *mid = divide(head); // 从中间切开
    ListNode *newHead = reverse(mid->next); // 翻转后半部分
    mid->next = nullptr;
    MergeList(head, newHead); // 交叉合并
}

int main() {
    string s = "Hello, World!";
    next_permutation(s.begin(), s.end());
    cout << s << endl;

    return 0;
}
