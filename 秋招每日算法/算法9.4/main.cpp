#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 48. 旋转图像
void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            if (i == j)
                break;
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {
    }
};

// 437. 路径总和 III
typedef long long LL;
// 以该节点为根 向下探索
LL dfs(TreeNode *root, LL targetSum) {
    if (!root)
        return 0;
    int ret = dfs(root->left, targetSum - root->val) +
              dfs(root->right, targetSum - root->val);
    if (targetSum - root->val == 0)
        return 1 + ret;
    return ret;
}

LL pathSum(TreeNode *root, LL targetSum) {
    if (!root)
        return 0;
    return pathSum(root->left, targetSum) +
           pathSum(root->right, targetSum) + dfs(root, targetSum);
}

// 102. 二叉树的层序遍历
vector<vector<int> > levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int> > ans;
    if (!root)
        return ans;
    q.push(root);
    while (q.size()) {
        int size = q.size();
        vector<int> ret;
        while (size--) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            ret.push_back(tmp->val);
        }
        ans.emplace_back(ret);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
