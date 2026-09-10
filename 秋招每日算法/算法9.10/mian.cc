#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 470. 用 Rand7() 实现 Rand10()

int rand10() {
    int x;
    do {
        // 0 7 14 21 28 35 42 + 1-7 = 1 - 49 等概率
        x = (rand7() - 1) * 7 + rand7();
    } while (x > 40);
    return x % 10 + 1;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 110. 平衡二叉树
// 返回该子树的最大高度
int dfs(TreeNode *root) {
    if (!root)
        return 0;
    return max(dfs(root->left), dfs(root->right)) + 1;
}
bool isBalanced(TreeNode *root) {
    if (!root)
        return true;
    if (abs(dfs(root->left) - dfs(root->right)) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

// 15. 三数之和
vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int x = nums[i] + nums[l] + nums[r];
            if (x == 0) {
                ans.push_back({nums[i], nums[l], nums[r]});
                do {
                    r--;
                } while (l < r && nums[r + 1] == nums[r]);
                do {
                    l++;
                } while (l < r && nums[l - 1] == nums[l]);
            } else if (x > 0) {
                do {
                    r--;
                } while (l < r && nums[r + 1] == nums[r]);

            } else {
                do {
                    l++;
                } while (l < r && nums[l - 1] == nums[l]);
            }
        }
    }
    return ans;
}