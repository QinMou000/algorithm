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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    // 求经过当前节点的最大路径保存到ans里面
    // 返回值为经过该节点的单边最大路径
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        // 如果单边路径小于0 那就不要
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        // 更新结果
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
};

// link : https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked