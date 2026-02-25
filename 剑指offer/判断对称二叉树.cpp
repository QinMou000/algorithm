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
    bool checkSymmetricTree(TreeNode* root) {
        if (!root)
            return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode* L, TreeNode* R) {
        if (!L && !R)
            return true;
        if (!L || !R)
            return false;
        // L 和 R 都存在
        if (L->val != R->val)
            return false;
        return check(L->left, R->right) && check(L->right, R->left);
    }
};

// link : https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p