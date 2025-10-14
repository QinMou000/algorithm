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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            vector<int> ret;
            // 记录下当前队列大小 就是本层的节点数量
            int size = Q.size();
            // 将当前层的节点都push进ret里面 并将下一层的节点都带入队列
            while (size) {
                TreeNode* cur = Q.front();
                Q.pop();
                ret.push_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
                size--;
            }
            ans.push_back(ret);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/binary-tree-level-order-traversal/?envType=study-plan-v2&envId=top-100-liked