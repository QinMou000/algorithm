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
// public:
//     bool isValidBST(TreeNode* root) {
//         if (!root)
//             return true;
//         if (!root->left && !root->right) // 如果两个孩子都为空 返回真
//             return true;
//         if (!root->left) // 如果其中一个孩子为空 判断另一个是否符合规则
//             return root->right->val > root->val;
//         if (!root->right)
//             return root->left->val < root->val;
//         if (root->left->val < root->val && root->right->val > root->val)
//             return isValidBST(root->left) && isValidBST(root->right);
//         else
//             return false;
//         return true;
//     }
// };
// 哪个甜菜写的傻逼代码 看清题目 是整个左子树和整个右子树的值
// 节点的左子树只包含 严格小于 当前节点的数。
// 节点的右子树只包含 严格大于 当前节点的数。

class Solution {
public:
    vector<int> arr;
    void recursion(TreeNode* root) {
        if (!root)
            return;
        recursion(root->left);
        arr.push_back(root->val);
        recursion(root->right);
    }
    bool isValidBST(TreeNode* root) {
        recursion(root); // 中序遍历存数组 判断是否为升序
        for (int i = 0; i < arr.size() - 1; ++i)
            if (arr[i] >= arr[i + 1])
                return false;
        return true;
    }
};

class Solution { // 官方题解
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
};

// link : https://leetcode.cn/problems/validate-binary-search-tree/?envType=study-plan-v2&envId=top-100-liked
