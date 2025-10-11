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
class Solution {
public:
    void recursion(TreeNode* root) {
        if (!root)
            return;
        TreeNode* tmp = root->left; // 交换左子树和右子树
        root->left = root->right;
        root->right = tmp;
        recursion(root->left); // 递归左右子树
        recursion(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        recursion(root);
        return root;
    }
};

// link : https://leetcode.cn/problems/invert-binary-tree/?envType=study-plan-v2&envId=top-100-liked