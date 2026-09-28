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
    typedef unsigned long long ULL; // 避免二叉树过大 数据溢出
    int widthOfBinaryTree(TreeNode *root) {
        // 把二叉树看成满二叉树 为它编号（类似于堆）
        vector<pair<TreeNode *, ULL>> vec; // 节点,编号
        vec.push_back({root, 0});
        ULL ans = 1;
        while (!vec.empty()) {
            vector<pair<TreeNode *, ULL>> tmp; // 用来存储下一层的节点
            for (auto e : vec) {
                if (e.first->left)
                    tmp.emplace_back(e.first->left, e.second * 2);
                if (e.first->right)
                    tmp.emplace_back(e.first->right, e.second * 2 + 1);
            }
            // 计算当前层的最大宽度
            ans = max(ans, vec.back().second - vec[0].second + 1);
            vec = move(tmp);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/maximum-width-of-binary-tree/description/