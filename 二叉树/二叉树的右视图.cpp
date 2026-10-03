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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        if (!root)
            return ans;
        while (!q.empty()) {
            int size = q.size();
            vector<int> ret;
            while (size--) {
                TreeNode *tmp = q.front();
                q.pop();
                if (size == 0)
                    ans.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/WNC0Lk/description/