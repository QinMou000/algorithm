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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n - 1); // 左闭右闭区间
    }

private:
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        // 找到最大值和对应下标
        int index = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[index])
                index = i;
        }
        // 创建当前子树根节点
        TreeNode* root = new TreeNode(nums[index]);
        // 递归创建左右子树
        root->left = dfs(nums, left, index - 1);
        root->right = dfs(nums, index + 1, right);
        return root;
    }
};

// link : https://leetcode.cn/problems/maximum-binary-tree/