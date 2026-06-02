/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public: // 递归中序遍历后 返回第k-1个元素
//     vector<int> ans;
//     void recursion(TreeNode* root) {
//         if (!root)
//             return;
//         recursion(root->left);
//         ans.push_back(root->val);
//         recursion(root->right);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         recursion(root);
//         return ans[k - 1];
//     }
// };

class Solution {
public: // 和中序遍历几乎一样
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            k--;
            if (k == 0)
                break;
            root = root->right;
        }
        return root->val;
    }
};

// 第二遍写:

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     // 中序递归
//     int ans = 0;
//     int kthSmallest(TreeNode* root, int k) {
//         int cur = 0;
//         dfs(root, k, cur);
//         return ans;
//     }
//     // cur需要传引用每次都对同一个副本进行++
//     void dfs(TreeNode* root, int k, int& cur) {
//         if (!root)
//             return;
//         dfs(root->left, k, cur);
//         cur++;
//         if (cur == k) {
//             ans = root->val;
//             return;
//         }
//         dfs(root->right, k, cur);
//     }
// };

class Solution {
public:
    // 用栈来迭代
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        int cnt = 0;

        while (cur || !stk.empty()) {
            while (cur) {
                // 一直向左走
                stk.push(cur);
                cur = cur->left;
            }
            // 弹出最左边的节点
            cur = stk.top();
            stk.pop();
            // 访问当前节点
            cnt++;
            if (cnt == k)
                return cur->val;

            // 访问当前节点的右子树
            cur = cur->right;
        }
        return -1;
    }
};

// link : https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked