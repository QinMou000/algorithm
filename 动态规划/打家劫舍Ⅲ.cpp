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
    // (不)选择当前节点下, 当前节点的子树被选择的最大权值和
    unordered_map<TreeNode *, int> f, g;
    int rob(TreeNode *root) {
        dfs(root);
        return max(f[root], g[root]);
    }
    void dfs(TreeNode *root) {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        // 选择当前节点,但其子节点不能选择
        f[root] = g[root->left] + g[root->right] + root->val;
        // 不选择当前节点,其子节点可以选可以不选
        g[root] = max(g[root->left], f[root->left]) + max(g[root->right], f[root->right]);
    }
};

// link : https://leetcode.cn/problems/house-robber-iii/description/