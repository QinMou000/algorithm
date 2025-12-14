/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) { return dfs(root); }

private:
    int dfs(Node* root) {
        if (root == nullptr)
            return 0;
        else {
            int Maxdepht = 1;               // root不为空所以至少深度为1
            for (auto e : root->children) { // 遍历每一个孩子
                int tmp = dfs(e) + 1;       // 对每个孩子递归搜索
                if (tmp > Maxdepht)         // 取最大的一条路线返回
                    Maxdepht = tmp;
            }
            return Maxdepht;
        }
    }
};

// link : https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/