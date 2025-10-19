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
public: // 层序遍历最后一个元素就是我们想要的
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            // 队列中最后一个元素就是本层的最右边的节点
            ans.push_back(Q.back()->val);
            while (size > 0) {
                // 把这一层的节点拿出来并把下一层的节点 push 进去
                TreeNode* cur = Q.front();
                Q.pop();
                // if (size == 1) // 将本层最后一个节点的值 push_back 进 ans
                // 里面
                //     ans.push_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
                --size;
            }
        }
        return ans;
    }
};

// void dfs(TreeNode* root, int depth, vector<int>& ans) {
//     if (!root)
//         return;

//     if (depth == ans.size())
//         ans.push_back(root->val);

//     dfs(root->right, depth + 1, ans);
//     dfs(root->left, depth + 1, ans);
// }

// vector<int> rightSideView(TreeNode* root) {
//     vector<int> ans;
//     dfs(root, 0, ans);
//     return ans;
// }

// 思路：先递归右子树，再递归左子树，当某个深度首次到达时，对应的节点就在右视图中。

// link : https://leetcode.cn/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-100-liked