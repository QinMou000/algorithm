/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map; // 旧链表节点和新链表节点间的映射
        Node* cur = head;
        while (cur) {
            Node* NewNode = new Node(cur->val);
            map[cur] = NewNode;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            // 通过旧链表去链接新链表
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};

// link : https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p