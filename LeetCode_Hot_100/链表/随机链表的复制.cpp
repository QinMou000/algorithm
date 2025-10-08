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
        Node* cur = head;
        unordered_map<Node*, Node*> map; // 映射的是 旧链表和新链表的指针
        while (cur) {
            // 将创建的新链表的节点暂时存在 hash 里面
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            // 将新链表的 next 指针和 ramdon 链接起来
            map[cur]->next = map[cur->next];
            // 表示新链表的 random 指针 指向
            // 旧链表节点 random 指向的 节点 对应在 map 里面映射的新链表节点
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head]; // 返回新链表的头节点
    }
};

// link : https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-100-liked