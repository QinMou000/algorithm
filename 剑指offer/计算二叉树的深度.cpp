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
    int calculateDepth(TreeNode *root) {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *root, int depth) {
            if (!root)
                return 0;
            int leftdepth = dfs(root->left, depth);
            int rightdepth = dfs(root->right, depth);
            ans = max(leftdepth, rightdepth) + 1;
            return ans;
        };
        dfs(root, 0);
        return ans;
    }
};

// link : https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/?envType=problem-list-v2&envId=XApvNy3p