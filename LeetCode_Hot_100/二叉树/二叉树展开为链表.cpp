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
// // 将节点存进数组里面重新排列
// class Solution {
// public:
//     vector<TreeNode*> tmp;
//     void recursion(TreeNode* root) {
//         if (!root)
//             return;
//         tmp.push_back(root);
//         recursion(root->left);
//         recursion(root->right);
//     }
//     void flatten(TreeNode* root) {
//         recursion(root);
//         for (int i = 1; i < tmp.size(); i++) {
//             TreeNode* cur = tmp[i];
//             TreeNode* prev = tmp[i - 1];
//             prev->left = nullptr;
//             prev->right = cur;
//         }
//     }
// };

// 递归写法 TODO
class Solution {
public:
    TreeNode* tmp = nullptr;
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = tmp;    // 当前节点的右指针指向tmp（上一个处理的节点）
        root->left = nullptr; // 左指针置空（符合单链表要求）
        tmp = root;           // 更新tmp为当前节点（供父节点使用）
    }
};

// link : https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked