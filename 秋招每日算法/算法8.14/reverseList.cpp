#include <iostream>

struct ListNode {
    ListNode *next;
    int val;

    ListNode() : next(nullptr), val(0) {
    }

    ListNode(int value, ListNode *ptr) : val(value), next(ptr) {
    }
};

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next = cur->next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void PrintList(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        std::cout << cur->val << "->";
        cur = cur->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode *node5 = new ListNode(5, nullptr);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    PrintList(node1);

    ListNode *newhead = reverseList(node1);

    PrintList(newhead);

    return 0;
}
