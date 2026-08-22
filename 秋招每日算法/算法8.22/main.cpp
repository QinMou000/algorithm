#include <iostream>
#include <vector>

class Solution {
public:
    // 42. 接雨水
    int trap(std::vector<int> &height) {
        int n = height.size();
        int soild = 0;
        int maxH = 0;
        for (auto e: height) {
            soild += e;
        }
        int l = 0, r = n - 1;
        int sum = 0;
        int h = 1;
        while (l <= r) {
            while (l <= r && height[l] < h) {
                l++;
            }
            while (l <= r & height[r] < h) {
                r--;
            }
            sum += (r - l + 1);
            h++;
        }
        return sum - soild;
    }

    // 53. 最大子数组和
    int maxSubArray(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, 0); // 以i为结尾的最大子数组和
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }

    // 236. 二叉树的最近公共祖先
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {
        }
    };

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q)
            return root; // 如果root为空或者root就是p或者q直接返回
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (l && r) // 如果左右子树分别找到了p q root就是他们的公共祖先
            return root;
        // 否则就返回递归存在的结果 递归结束后的left或者right
        return !l ? r : l;
    }

    // 153. 寻找旋转排序数组中的最小值
    // nums = [3,4,5,1,2]
    int findMin(std::vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int div = nums[n - 1]; // 找最后一个为基点 不要找第一个会越界
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > div) {
                l++;
            } else {
                r--;
            }
        }
        return nums[l];
    }

    // 240. 搜索二维矩阵 II
    bool searchMatrix(std::vector<std::vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {
        // 3, 4, 5, 1, 2
        11, 13, 15, 17
    };
    Solution s;
    s.findMin(nums);
    return 0;
}
