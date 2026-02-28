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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        bool x = true;
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // 记录当前层的节点数量
            int size = q.size();
            vector<int> ret;
            while (size) {
                TreeNode* Front = q.front();
                q.pop();
                ret.push_back(Front->val);
                if (Front->left)
                    q.push(Front->left);
                if (Front->right)
                    q.push(Front->right);
                size--;
            }
            if (!x)
                reverse(ret.begin(), ret.end());
            ans.push_back(ret);
            // 改变下一层的顺序
            x = !x;
        }
        return ans;
    }
};