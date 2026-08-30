#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// 207. 课程表
bool canFinish(int n, vector<vector<int> > &prerequisites) {
    unordered_map<int, vector<int> > edges; // 邻接表
    vector<int> in(n); // 入度表
    // 建图
    for (auto e: prerequisites) {
        edges[e[1]].push_back(e[0]);
        in[e[0]]++;
    }
    queue<int> q;
    // 把所有入度为零的节点加入队列
    for (int i = 0; i < n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        // do something
        for (int e: edges[t]) {
            in[e]--; // 在入度表中删除一些边
            if (in[e] == 0) // 删除之后 如果当前节点的入度为零
                q.push(e);
        }
    }
    for (auto e: in) // 判断入度表是否全为零
        if (e == 1)
            return false;
    return true;
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

// 106. 从中序与后序遍历序列构造二叉树
unordered_map<int, int> index_map;
int cur_index; // 后序序列专用
TreeNode *helper(int l, int r, vector<int> &ino, vector<int> &posto) {
    if (l > r)
        return nullptr;
    int root_val = posto[cur_index];
    TreeNode *root = new TreeNode(root_val);

    cur_index--; // 后序序列下标减一

    int index = index_map[root_val]; // 中序专用
    // 根据后续序列的顺序走 先构建右子树
    root->right = helper(index + 1, r, ino, posto);
    root->left = helper(l, index - 1, ino, posto);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = postorder.size();
    cur_index = n - 1;
    for (int i = 0; i < inorder.size(); i++)
        index_map[inorder[i]] = i; // 值->下标
    return helper(0, n - 1, inorder, postorder);
}

// class Solution {
//     vector<int> _nums;

// public:
//     Solution(vector<int>& nums) : _nums(nums) {}

//     int pick(int target) {
//         int ans;
//         for (int i = 0, cnt = 0; i < _nums.size(); ++i) {
//             if (target == _nums[i]) {
//                 ++cnt;
//                 if (rand() % cnt == 0) {
//                     ans = i;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 398. 随机数索引
class Solution1 {
    unordered_map<int, vector<int> > map; // 值->下标
public:
    Solution1(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> indexs = map[target];
        return indexs[rand() % indexs.size()];
    }
};

// 2958. 最多 K 个重复元素的最长子数组
int maxSubarrayLength(vector<int> &nums, int k) {
    unordered_map<int, int> map; // 值->出现次数
    int n = nums.size();
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        map[nums[r]]++;
        while (map[nums[r]] > k) {
            map[nums[l++]]--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// 105. 从前序与中序遍历序列构造二叉树
class Solution2 {
public:
    unordered_map<int, int> map; // 值->下标
    int cur_index; // 前序遍历专用
    TreeNode *helper(vector<int> &pre, vector<int> &ino, int l, int r) {
        if (l > r)
            return nullptr;

        int cur_val = pre[cur_index];
        TreeNode *root = new TreeNode(cur_val);

        int mid = map[cur_val]; // 当前节点中序遍历的位置

        cur_index++;

        root->left = helper(pre, ino, l, mid - 1);
        root->right = helper(pre, ino, mid + 1, r);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        cur_index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, inorder.size() - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
