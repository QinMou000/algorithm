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
//     bool recursion(TreeNode* L, TreeNode* R) {
//         if (!L && !R) // 如果左右子树都为空 返回真
//             return true;
//         if (!L || !R) // 如果左右子树只有一个为空 返回假
//             return false;
//         // 如果左右子树值相同 返回判断
//         // 左树的左孩子与右树的右孩子对称
//         // 左树的右孩子与右树的左孩子对称 的结果
//         if (L->val == R->val)
//             return (recursion(L->left, R->right) &&
//                     recursion(L->right, R->left));
//         else // 如果左右子树值不同 返回假
//             return false;
//     }
//     bool isSymmetric(TreeNode* root) {
//         if (!root)
//             return true;
//         return recursion(root->left, root->right);
//     }
// };

// 如何用迭代的方式解决:层序遍历
// 首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。
// 初始化时我们把根节点入队两次。每次提取两个结点并比较它们的值
// （队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像）
// 然后将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，
// 或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，
// 该算法结束。

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        while (!Q.empty()) {
            auto m = Q.front();
            Q.pop();
            auto n = Q.front();
            Q.pop();
            // 两者都为空 本应该返回真 但是这是在主函数里面
            // 并且还有数据没有遍历完 应该继续遍历
            if (!m && !n)
                continue;
            if (!m || !n)
                return false;
            if (m->val != n->val)
                return false;

            // 注意这里下一层的插入顺序 是相反的
            Q.push(m->left);
            Q.push(n->right);

            Q.push(m->right);
            Q.push(n->left);
        }
        return true;
    }
};
// link : https://leetcode.cn/problems/symmetric-tree/?envType=study-plan-v2&envId=top-100-liked
