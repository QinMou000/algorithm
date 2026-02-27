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
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // 本层数量
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
            ans.push_back(ret);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/description/?envType=problem-list-v2&envId=XApvNy3p