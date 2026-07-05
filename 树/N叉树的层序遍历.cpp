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
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> ret;
            for (int i = 0; i < size; i++) {
                Node *tmp = q.front();
                q.pop();
                if (!tmp->children.empty())
                    for (Node *node : tmp->children)
                        q.push(node);
                ret.push_back(tmp->val);
            }
            if (!ret.empty()) {
                ans.emplace_back(ret);
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/