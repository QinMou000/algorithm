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
    int findTargetNode(TreeNode *root, int cnt) {
        int ans = 0;
        auto dfs = [&](this auto &&dfs, TreeNode *root, int &rank) {
            if (!root)
                return;
            // 访问右子树
            dfs(root->right, rank);
            --rank; // 访问当前节点位次减一
            if (rank == 0) {
                ans = root->val;
            }
            // 访问左子树
            dfs(root->left, rank);
        };
        dfs(root, cnt);
        return ans;
    }
};

// link :
// https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/description/?envType=problem-list-v2&envId=XApvNy3p