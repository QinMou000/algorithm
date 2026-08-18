#include <iostream>
#include <vector>
#include <functional>

class Solution {
public:
    // 合并两个有序数组
    // nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1;
        int dst = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[dst--] = nums2[j--];
            } else {
                nums1[dst--] = nums1[i--];
            }
        }
        while (j >= 0) {
            nums1[dst--] = nums2[j--];
        }
    }

    // 二叉树的中序遍历
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

    std::vector<int> ans;

    std::vector<int> inorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root) {
        if (!root) return;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }

    // 复原IP地址
    std::vector<std::string> restoreIpAddresses(std::string s) {
        // 判断s [i,j) 是否满足要求
        // 如果 t 的长度大于 1 且 t[0]=‘0’，那么 t 有前导零，不符合要求。
        // 否则，t 对应的整数必须 ≤255，否则不符合要求。可以先判断 t 的长度是否超过 3，超过就直接判定为不合法。
        std::function<bool(int i, int j)> check = [&](int i, int j)-> bool {
            if (j - i > 3 || (j - i > 1 && s[i] == '0'))
                return false;

            return std::stoi(s.substr(i, j - i)) <= 255;
        };
        int n = s.size();
        std::vector<std::string> ans;
        for (int i = 1; i < n && check(0, i); i++) {
            for (int j = i + 1; j < n && check(i, j); j++) {
                for (int k = j + 1; k < n && check(j, k); k++) {
                    if (check(k, n)) {
                        ans.push_back(s.substr(0, i) + "."
                                      + s.substr(i, j) + "."
                                      + s.substr(j, k) + "."
                                      + s.substr(k));
                    }
                }
            }
        }
        return ans;
    }

    // 单链表每两个节点反转 TODO
    // 判断一棵树是否为另一棵树的子树 TODO
    // 课程表 TODO
};

int main() {
    // std::vector<int> arr = {2, 5, 6};
    //
    // std::cout << *arr.begin() << std::endl; // begin() ,end() 是左闭右开区间
    // std::cout << *arr.end() << std::endl;
    //
    // arr.insert(arr.begin(), 1); // insert 是在迭代器之前插入 返回插入数字的迭代器

    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};

    Solution s;
    s.merge(nums1, 3, nums2, 3);

    for (auto e: nums1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
