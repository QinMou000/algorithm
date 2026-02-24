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
    TreeNode* flipTree(TreeNode* root) {
        this->swap(root);
        return root;
    }
    void swap(TreeNode* root) {
        if (!root)
            return;
        if (!root->left && !root->right)
            return;
        // left right 存在一个或者都存在
        if (!root->left) {
            root->left = root->right;
            root->right = nullptr;
        } else if (!root->right) {
            root->right = root->left;
            root->left = nullptr;
        } else {
            std::swap(root->left, root->right);
        }
        this->swap(root->left);
        this->swap(root->right);
        return;
    }
};

// link : https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/description/?envType=problem-list-v2&envId=XApvNy3p