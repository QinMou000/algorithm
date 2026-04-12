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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        // 分别记录左右子树的最大深度
        int right = dfs(root->right);
        int left = dfs(root->left);
        ans = max(right + left, ans); // 更新 ans 
        return max(right, left) + 1; // 返回以该节点为根 左右子树的最大深度
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// 第二遍写
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    // 找左右子树的最大深度
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int left_len = dfs(root->left);
        int right_len = dfs(root->right);
        ans = max(left_len + right_len, ans);
        return max(left_len, right_len) + 1;
    }
};

// link : https://leetcode.cn/problems/diameter-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked