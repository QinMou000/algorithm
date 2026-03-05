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
// // dfs
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         return dfs(root, targetSum);
//     }
//     bool dfs(TreeNode* root, int tarNum) {
//         if (!root)
//             return false;
//         if (tarNum - root->val == 0 && (!root->left && !root->right))
//             return true;
//         return dfs(root->left, tarNum - root->val) ||
//                dfs(root->right, tarNum - root->val);
//     }
// };

// bfs
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        queue<TreeNode*> q_node;
        queue<int> q_val;
        q_node.push(root);
        q_val.push(root->val);
        while (!q_node.empty()) {
            TreeNode* node = q_node.front();
            q_node.pop();
            int val = q_val.front();
            q_val.pop();
            if (!node->left && !node->right) {
                if (val == targetSum)
                    return true;
                // 这里不能直接 写成return val == targetSum
                // 这意味着只要遇到第一个叶子节点就会返回结果，
                // 而不管这个叶子节点的路径和是否等于目标值，
                // 也不会继续检查其他叶子节点。
                continue; // 跳过下面的代码继续下一次循环
            }
            if (node->left) {
                q_node.push(node->left);
                q_val.push(node->left->val + val);
            }
            if (node->right) {
                q_node.push(node->right);
                q_val.push(node->right->val + val);
            }
        }
        return false;
    }
};

// link : https://leetcode.cn/problems/path-sum/description/