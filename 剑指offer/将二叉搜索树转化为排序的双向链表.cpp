/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        dfs(root);
        head->left = pre;
        // 全部遍历完之后 pre就是链表的tail节点
        pre->right = head;
        return head;
    }
    Node *pre, *head;
    // pre用于记录双向链表中位于root左侧的节点 即上一次迭代中的root
    void dfs(Node* root) {
        if (!root)
            return;
        dfs(root->left);
        // 当pre==null时 root左侧没有节点 即此时root为双向链表中的头节点
        if (pre == nullptr)
            head = root;
        // 反之 pre!=null时 root左侧存在节点pre 需要进行pre->right=root的操作
        else
            pre->right = root;
        // pre是否为null对这句没有影响 且这句放在上面两句if else之前也是可以的
        root->left = pre;
        pre = root;       // pre指向当前的root
        dfs(root->right); // 全部迭代完成后 pre指向双向链表中的尾节点
    }
};

// link : https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/?envType=problem-list-v2&envId=XApvNy3p