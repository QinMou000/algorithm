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
    vector<int> ans;
    vector<int> preorder(Node *root) {
        bfs(root);
        return ans;
    }
    void bfs(Node *root) {
        if (!root)
            return;
        ans.push_back(root->val);
        for (auto node : root->children) {
            bfs(node);
        }
    }
};

// link : https://leetcode.cn/problems/n-ary-tree-preorder-traversal/