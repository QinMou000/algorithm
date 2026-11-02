// 61. 旋转链表

ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
        return nullptr;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        n++;
        cur = cur->next;
    }
    cur->next = head; // 串成环形链表
    int step = n - k % n;
    while (step--) {
        cur = cur->next;
    }
    ListNode *NewHead = cur->next;
    cur->next = nullptr;

    return NewHead;
}