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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        if (!root)
            return ans;
        bool flag = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> ret;
            while (size--) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                ret.push_back(tmp->val);
            }
            if (!flag) {
                reverse(ret.begin(), ret.end());
            }
            flag = !flag;
            ans.emplace_back(ret);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/