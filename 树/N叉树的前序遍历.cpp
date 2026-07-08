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

// 非递归做法
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* tmp = stk.top();
            stk.pop();
            ans.push_back(tmp->val);
            // 用反向迭代器
            auto rit = tmp->children.rbegin();
            while (rit != tmp->children.rend()) {
                stk.push(*rit);
                rit++;
            }
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/n-ary-tree-preorder-traversal/