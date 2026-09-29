// 933. 最近的请求次数

class RecentCounter {
    queue<int> q;

  public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

// 2166. 设计位集
class Bitset {
    vector<uint8_t> nums;
    int cnt = 0;     // 1的个数
    int reserve = 0; // 翻转操作的次数 0:翻转偶数次 1 翻转奇数次
                     // 异或：相同为 0，不同为 1
  public:
    Bitset(int size) { nums.resize(size); }

    void fix(int idx) {
        if (nums[idx] ^ reserve == 0) {
            nums[idx] ^= 1;
            cnt++;
        }
    }

    void unfix(int idx) {
        // 两者都为0 或者都为1
        if (nums[idx] ^ reserve == 1) {
            nums[idx] ^= 1;
            cnt--;
        }
    }

    void flip() {
        reserve ^= 1;
        cnt = nums.size() - cnt;
    }

    bool all() { return nums.size() == cnt; }

    bool one() { return cnt > 0; }

    int count() { return cnt; }

    string toString() {
        string str = "";
        for (auto &bit : nums)
            str += ((bit ^ reserve) + '0');
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

// 105. 从前序与中序遍历序列构造二叉树
class Solution {
  public:
    unordered_map<int, int> map; // 数字 中序遍历的下标
    int pre_idx = 0;             // 前序遍历专用
    // l r都是中序遍历专用
    TreeNode *Helper(vector<int> &pre, int l, int r) {
        if (l > r)
            return nullptr;
        TreeNode *node = new TreeNode(pre[pre_idx]);

        int mid = map[pre[pre_idx]];
        pre_idx++;
        node->left = Helper(pre, l, mid - 1);
        node->right = Helper(pre, mid + 1, r);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return Helper(preorder, 0, preorder.size() - 1);
    }
};

// 30. 二叉搜索树中第 K 小的元素
int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (stk.size() || cur) {
        while (cur) {
            // 左边节点全部入栈
            stk.push(cur);
            cur = cur->left;
        }
        // 取到未遍历的最左侧节点
        cur = stk.top();
        stk.pop();
        if (--k == 0)
            return cur->val;
        // 访问右侧节点
        cur = cur->right;
    }
    return -1;
}

// 300. 最长递增子序列
int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // 以i位置结尾的最长递增子序列长度
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// 662. 二叉树最大宽度
typedef unsigned long long ULL;
int widthOfBinaryTree(TreeNode *root) {
    vector<pair<TreeNode *, ULL>> heap;
    ULL ans = 0;
    heap.push_back(make_pair(root, 1));
    while (heap.size()) {
        vector<pair<TreeNode *, ULL>> tmp;
        // 这里类似于层序遍历
        for (auto Pair : heap) {
            if (Pair.first->left)
                tmp.push_back(make_pair(Pair.first->left, Pair.second * 2));
            if (Pair.first->right)
                tmp.push_back(make_pair(Pair.first->right, Pair.second * 2 + 1));
        }
        ans = max(ans, heap.back().second - heap[0].second + 1);
        heap = std::move(tmp);
    }
    return ans;
}

// 143. 重排链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *FindMid(ListNode *head) {
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout << slow->val << endl;
        return slow;
    }
    ListNode *Reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = cur->next;
        while (cur) {
            // cout << cur->val << endl;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void Merge(ListNode *head1, ListNode *head2) {
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;
        ListNode *next;
        while (cur1 && cur2) {
            next = cur1->next;
            cur1->next = cur2;
            cur1 = next;

            next = cur2->next;
            cur2->next = cur1;
            cur2 = next;
        }
    }
    void reorderList(ListNode *head) {
        if (!head || !head->next)
            return;
        // 找中点
        ListNode *mid = FindMid(head);
        // 翻转后半部分
        ListNode *half = mid->next;
        mid->next = nullptr;
        ListNode *head2 = Reverse(half);
        // 合并
        Merge(head, head2);
    }
};

// 53. 最大子数组和
int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        ans = max(dp[i], ans);
    }
    return ans;
}

// 895. 最大频率栈
class FreqStack {
  public:
    FreqStack() { max_freq = 0; }

    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        max_freq = max(max_freq, freq[val]);
    }

    int pop() {
        int x = group[max_freq].top();
        freq[x]--;
        group[max_freq].pop();
        if (group[max_freq].empty())
            max_freq--;
        return x;
    }

  private:
    unordered_map<int, int> freq;         // 每个数->出现频率
    unordered_map<int, stack<int>> group; // 每个频率->栈
    int max_freq;                         // 当前出现频率的最大值
};