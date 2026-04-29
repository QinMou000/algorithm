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
    int pathSum(TreeNode* root, int targetSum) {
        // key：从根到 node 的节点值之和
        // value：节点值之和的出现次数
        // 注意在递归过程中，哈希表只保存根到 node 的路径的前缀的节点值之和
        unordered_map<long long, int> map = {{0, 1}};

        int ans = 0;
        // s 表示从根到 node 的父节点的节点值之和（node 的节点值尚未计入）
        auto dfs = [&](this auto&& dfs, TreeNode* root, long long sum) {
            if (!root)
                return;
            sum += root->val;
            // 把当前 root 当作路径的终点，统计有多少个起点
            ans += map[sum - targetSum];

            map[sum]++;
            dfs(root->left, sum);
            dfs(root->right, sum);
            // 因为是树结构，所以需要恢复现场
            map[sum]--; // 恢复现场（撤销 cnt[sum]++）
        };
        dfs(root, 0);
        return ans;
    }
};

// link : https://leetcode.cn/problems/path-sum-iii/?envType=study-plan-v2&envId=top-100-liked