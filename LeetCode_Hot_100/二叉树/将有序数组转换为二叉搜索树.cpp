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
    TreeNode* recursion(vector<int>& nums, int left, int right) {
        if (left > right) // left 可以等于 right 
            return nullptr;
        // 每次取数组中点左边的数组新建节点
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // 递归新建当前节点的左右子树
        root->left = recursion(nums, left, mid - 1);
        root->right = recursion(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size() - 1);
    }
};

// link : https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-100-liked