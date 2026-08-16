#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

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

class Solution {
public:
    // 二叉树的锯齿形层序遍历
    std::vector<std::vector<int> > zigzagLevelOrder(TreeNode *root) {
        std::vector<std::vector<int> > ans;
        if (!root)
            return ans;
        std::queue<TreeNode *> q;
        q.push(root);
        bool flag = 0;
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> ret;
            while (size--) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                ret.push_back(tmp->val);
            }
            if (flag)
                std::reverse(ret.begin(), ret.end());
            flag = !flag;
            ans.emplace_back(ret);
        }
        return ans;
    }

    std::vector<std::vector<int> > merge(std::vector<std::vector<int> > &intervals) {
        sort(intervals.begin(), intervals.end()); // 默认按左边界排序
        int left = intervals[0][0], right = intervals[0][1];
        std::vector<std::vector<int> > ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right) {
                right = std::max(right, intervals[i][1]);
            } else {
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};

int main() {
    Solution sol;
    // [3,9,20,null,null,15,7]
     TreeNode *node5 = new TreeNode(7);
     TreeNode *node4 = new TreeNode(15);
     TreeNode *node3 = new TreeNode(20, node4, node5);
     TreeNode *node2 = new TreeNode(9, nullptr, nullptr);
     TreeNode *node1 = new TreeNode(3, node2, node3);

     std::vector<std::vector<int> > ans;
     ans = sol.zigzagLevelOrder(node1);

     for (auto vec: ans) {
         for (auto e: vec) {
             std::cout << e << " ";
         }
         std::cout << std::endl;
     }

    return 0;
}
