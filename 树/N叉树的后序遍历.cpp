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
    vector<int> postorder(Node *root) {
        bfs(root);
        return ans;
    }
    void bfs(Node *root) {
        if (!root)
            return;
        for (auto node : root->children) {
            bfs(node);
        }
        ans.push_back(root->val);
    }
};

class Solution {
  public:
    vector<int> ans;
    vector<int> postorder(Node *root) {
        // 栈1存节点 按照 中右左 遍历树
        stack<Node *> stk;
        // 弹出栈1时压入栈2, 最后取出栈2元素
        // 最后取出来 节点按照 左右中 排序
        stack<Node *> trueStk;
        stk.push(root);

        while (!stk.empty()) {
            Node *tmp = stk.top();
            stk.pop();
            // 在弹出栈1的时候将弹出节点压入栈2
            trueStk.push(tmp);
            auto it = tmp->children.begin();
            while (it != tmp->children.end()) {
                stk.push(*it);
                it++;
            }
        }
        while (!trueStk.empty()) {
            Node *node = trueStk.top();
            trueStk.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/n-ary-tree-postorder-traversal/