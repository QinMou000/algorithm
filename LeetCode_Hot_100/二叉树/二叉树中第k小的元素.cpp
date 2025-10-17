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

// link : https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked