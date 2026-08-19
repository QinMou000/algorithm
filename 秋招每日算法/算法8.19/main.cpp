#include <iostream>
#include <vector>
#include <functional>
#include <stack>


class Solution {
public:
    // 课程表
    bool canFinish(int numCourses, std::vector<std::vector<int> > &prerequisites) {
        std::vector<std::vector<int> > matrix(numCourses);
        for (auto &e: prerequisites) {
            matrix[e[1]].push_back(e[0]); // 要想完成课程e[1]就得先完成e[0]
        }
        std::vector<int> color(numCourses, 0); // 用color记录课程的访问情况

        // 返回true表示找到环
        std::function<bool(int i)> dfs = [&](int i) {
            color[i] = 1;
            // 0 未访问
            // 1 正在访问
            // 2 访问过
            for (auto e: matrix[i]) {
                // 遍历要完成i课程的所有前提课程
                if (color[e] == 1 || color[e] == 0 && dfs(e))
                    return true; // 有环 或者 前提课程中有环
            }
            color[i] = 2; // 以i开始这条线访问过了
            return false;
        };

        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0 && dfs(i)) {
                return false; // 有环 不能完成
            }
        }
        return true;
    }

    // 单链表每k个节点反转
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

    // 每次遍历链表时，把当前节点放入栈中。
    // 当栈中节点数量达到 k 时，说明已经凑齐了一组需要翻转的节点。
    // 此时依次弹出栈顶节点，重新连接这一组节点，就可以得到翻转后的顺序。
    // 如果最后剩余节点数量不足 `k`，则不进行翻转，保持原顺序。
    ListNode *reverseKGroup(ListNode *head, int k) {
        std::stack<ListNode *> stk;
        ListNode *dump = new ListNode(-1, head);
        ListNode *prev = dump; // 表示所有待翻转批次的前一个节点
        ListNode *cur = head;
        while (cur) {
            stk.push(cur);
            if (stk.size() == k) {
                ListNode *NewHead = cur; // 翻转后的头结点
                ListNode *Next = cur->next; // 下一个批次的第一个节点
                ListNode *NewTail = cur; // 翻转之后的尾节点

                while (!stk.empty()) {
                    NewTail->next = stk.top();
                    stk.pop();
                    NewTail = NewTail->next;
                }
                prev->next = NewHead; // 把前一个批次的最后一个节点接上
                NewTail->next = Next; // 把后一个批次的第一个节点接上
                prev = NewTail; // 更新待翻转批次的前一个节点
                cur = Next; // 下一个批次继续
            } else {
                cur = cur->next;
            }
        }
        return dump->next;
    }

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
        }
    };

    // 判断一棵树是否为另一棵树的子树
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root)
            return false;
        if (dfs(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    // 判断两颗树是否一样
    bool dfs(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val != subRoot->val)
            return false;
        return dfs(root->left, subRoot->left) &&
               dfs(root->right, subRoot->right);
    }

    // 1725. 可以形成最大正方形的矩形数目
    // 一次遍历
    int countGoodRectangles(std::vector<std::vector<int> > &rectangles) {
        int ans = 0;
        int maxlen = 0;
        for (auto pair: rectangles) {
            int l = pair[0], w = pair[1];
            int sidelength = std::min(l, w);
            if (sidelength == maxlen) {
                // 这里不用>= 因为如果大于就要更新maxlen了
                ans++;
            } else if (sidelength > maxlen) {
                ans = 1;
                maxlen = sidelength;
            }
        }

        return ans;
    }

    // 合并 K 个升序链表
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        ListNode *head = nullptr;
        for (auto list: lists) {
            ListNode *newHead = Merge(head, list);
            head = newHead;
        }
        return head;
    }

    ListNode *Merge(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2)
            return nullptr;
        if (!l1)return l2;
        if (!l2)return l1;

        ListNode *p = l1, *q = l2;
        ListNode *dump = new ListNode(-1);
        ListNode *cur = dump;
        while (p && q) {
            if (p->val > q->val) {
                cur->next = q;
                q = q->next;
            } else {
                cur->next = p;
                p = p->next;
            }
            cur = cur->next;
        }
        if (p)
            cur->next = p;
        if (q)
            cur->next = q;
        return dump->next;
    }

    // 45. 跳跃游戏 II
    // int jump(vector<int>& nums) {
    //     int lastmax = 0; // 上次跳到的最远
    //     int curmax = 0;  // 当前能跳到的最远
    //     int jumpcnt = 0; // 跳跃次数
    //     // 不用访问最后一个元素
    //     for (int i = 0; i < nums.size() - 1; i++) {
    //         curmax = max(curmax, nums[i] + i);
    //         if (i == lastmax) { // 到达上次最远边界
    //             // 再跳一次
    //             lastmax = curmax;
    //             jumpcnt++;
    //         }
    //     }
    //     return jumpcnt;
    // }
    int jump(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, INT_MAX / 2);
        dp[0] = 0; // 在0处不需要跳
        for (int i = 0; i < n; i++) {
            // 从i位置起跳
            for (int j = i + 1; j < n; j++) {
                // 如果能跳到j位置
                if (nums[i] + i >= j) {
                    dp[j] = std::min(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
