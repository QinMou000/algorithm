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
// class Solution { // 递归
// public:
//     vector<int> ans;
//     void recursion(TreeNode* root) {
//         if (!root)
//             return;
//         recursion(root->left);
//         ans.push_back(root->val);
//         recursion(root->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         recursion(root);
//         return ans;
//     }
// };

class Solution { // 迭代
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) { // root 不为空 并且栈不为空
            while (root) {
                stk.push(root);
                root = root->left; // 将所有左子树压栈
            }
            root = stk.top(); // 拿到当前根
            stk.pop();
            ans.push_back(root->val); // 访问当前根
            root = root->right;       // 继续右子树
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/binary-tree-inorder-traversal/?envType=study-plan-v2&envId=top-100-liked