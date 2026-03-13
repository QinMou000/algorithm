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
    int dfs(TreeNode* root, int targetSum) {
        // 以当前root节点为根 往下遍历 判断有多少满足的路径
        if (!root)
            return 0;

        int ret = 0;
        if (targetSum == root->val)
            ret++;
        ret += dfs(root->left, targetSum - root->val);
        ret += dfs(root->right, targetSum - root->val);
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        int ans = dfs(root, targetSum); // 以当前节点为根 判断有无满足的路径
        ans += pathSum(root->left, targetSum); // 分别遍历左右子树
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};

// link : https://leetcode.cn/problems/path-sum-iii/description/?envType=study-plan-v2&envId=top-100-liked