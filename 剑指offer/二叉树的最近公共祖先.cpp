/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 先判断当前位置为空 或者pq其中一个值等于root值 直接返回
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        // 当前节点肯定不是公共祖先 分别找左右子树
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 左右子树的结果 那个不为空就返回哪个 都不为空返回root
        // 说明pq分布在root的两侧
        return left == nullptr ? right : (right == nullptr ? left : root);
    }
};

// link :
// https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/description/?envType=problem-list-v2&envId=XApvNy3p