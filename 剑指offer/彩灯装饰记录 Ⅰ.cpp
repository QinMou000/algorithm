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
    // 二叉树层序遍历
    vector<int> decorateRecord(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (!root)
            return ans;
        q.push(root);
        while (!q.empty()) {
            TreeNode* topNode = q.front();
            q.pop();
            ans.push_back(topNode->val);
            if (topNode->left)
                q.push(topNode->left);
            if (topNode->right)
                q.push(topNode->right);
        }
        return ans;
    }
};