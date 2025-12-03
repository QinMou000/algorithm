/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         if (root == nullptr || root == p || root == q)
//             return root; // 如果root就是p或者q直接返回
//         // 在root的左右子树找p q
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);

//         if (left && right) // 如果左右子数分别找到了p q
//         root就是他们的公共祖先
//             return root;
//         // 否则就返回递归存在的结果 递归结束后的left或者right
//         return left ? left : right;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 先记录每一个节点的父节点
        dfs(root);
        // 分别从pq开始向上访问
        while (p) {
            visit[p] = true;
            p = father[p];
        }
        while (q) {
            if (visit[q] == true)
                return q;
            q = father[q];
        }
        return nullptr;
    }

private:
    unordered_map<TreeNode*, TreeNode*> father; // 记录下每一个节点的父节点是谁
    unordered_map<TreeNode*, bool> visit;       // 记录这个节点是否被访问过
    void dfs(TreeNode* root) {
        if (root->left) {
            father[root->left] = root;
            dfs(root->left);
        }
        if (root->right) {
            father[root->right] = root;
            dfs(root->right);
        }
    }
};

// link : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked