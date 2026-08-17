#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    // 数组中的第K个最大元素
    int findKthLargest(std::vector<int> &nums, int k) {
        int n = nums.size();
        if (n < k)
            return 0;
        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        int i = 0;
        for (; i < k; i++)
            pq.push(nums[i]);

        for (; i < n; i++) {
            if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    // 二叉树中的最大路径和
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
        }
    };

    int ans = INT_MIN;

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;

        int l = std::max(0, dfs(root->left));
        int r = std::max(0, dfs(root->right));

        ans = std::max(ans, (l + r + root->val));

        return std::max(l, r) + root->val;
    }

    // 螺旋矩阵
    std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = n - 1, d = m - 1, u = 0;
        std::vector<int> ans;
        while (true) {
            for (int i = l; i <= r; i++)
                ans.push_back(matrix[u][i]);
            if (++u > d)
                break;
            for (int i = u; i <= d; i++)
                ans.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int i = r; i >= l; i--)
                ans.push_back(matrix[d][i]);
            if (--d < u)
                break;
            for (int i = d; i >= u; i--)
                ans.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return ans;
    }
};

int main() {
    std::vector<int> arr1 = {
        3, 2, 1, 5, 6, 4
    };
    int k = 2;
    Solution s;
    std::cout << s.findKthLargest(arr1, k) << std::endl;
    return 0;
}
