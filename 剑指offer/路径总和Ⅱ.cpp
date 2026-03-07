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
// class Solution {
// private:
//     vector<vector<int>> ans;
//
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<int> path;
//         // 这里传的path是值一个函数栈帧都是不同的数组 不用回溯
//         dfs(root, targetSum, path);
//         return ans;
//     }
//     void dfs(TreeNode* root, int tarNum, vector<int> path) {
//         if (!root)
//             return;
//         path.push_back(root->val);
//         // 递归到叶子节点并且刚好满足条件
//         if (root->val == tarNum && (!root->left && !root->right))
//             ans.push_back(path);

//         dfs(root->left, tarNum - root->val, path);
//         dfs(root->right, tarNum - root->val, path);
//     }
// };

class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        // 这里path传的是应用 在本层递归结束后需要收回该值
        dfs(root, targetSum, path);
        return ans;
    }
    void dfs(TreeNode* root, int tarNum, vector<int>& path) {
        if (!root)
            return;
        path.push_back(root->val);
        // 递归到叶子节点并且刚好满足条件
        if (root->val == tarNum && (!root->left && !root->right))
            ans.push_back(path);

        dfs(root->left, tarNum - root->val, path);
        dfs(root->right, tarNum - root->val, path);
        path.pop_back();
    }
};

// link : https://leetcode.cn/problems/path-sum-ii/description/?envType=problem-list-v2&envId=XApvNy3p