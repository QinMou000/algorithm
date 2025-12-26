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
    // 前序遍历的值与中序遍历的值的下标的映射 val : index
    unordered_map<int, int> map;
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            map[inorder[i]] = i; // 值与下标的映射
        return recursion(preorder, inorder, 0, m - 1, 0, n - 1);
    }
    // left right 都是闭区间
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder,
                        int pre_left, int pre_right, int in_left,
                        int in_right) {
        if (pre_left > pre_right)
            return nullptr;
        int pre_root = preorder[pre_left];       // 前序遍历根节点
        int in_root_index = map[pre_root];       // 中序遍历根节点下标
        int in_root = inorder[in_root_index];    // 中序遍历的根节点
        TreeNode* root = new TreeNode(pre_root); // 新建前序遍历第一个节点

        // 中序遍历根节点的左边有几个未新建的节点
        int x = in_root_index - in_left;

        root->left = recursion(preorder, inorder, pre_left + 1, pre_left + x,
                               in_left, in_root_index - 1);
        root->right = recursion(preorder, inorder, pre_left + x + 1, pre_right,
                                in_root_index + 1, in_right);
        return root;
    }
};

// link : https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p