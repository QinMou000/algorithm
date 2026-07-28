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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        bool leftIsBalanced = isBalanced(root->left);
        if (!leftIsBalanced)
            return false;
        bool rightIsBalanced = isBalanced(root->right);
        if (!rightIsBalanced)
            return false;

        int left = dfs(root->left);
        int right = dfs(root->right);

        return abs(left - right) > 1 ? false : true;
    }
    int dfs(TreeNode* root) {
        // 算该子树的最大深度
        if (!root)
            return 0;
        int left = dfs(root->left) + 1;
        int right = dfs(root->right) + 1;
        return max(left, right);
    }
};

// link : https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/?envType=problem-list-v2&envId=XApvNy3p