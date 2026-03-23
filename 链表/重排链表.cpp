/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next)
            return;
        if (!head->next->next)
            return;
        // 从中间分割链表
        ListNode* mid = divide_mid(head);
        // 逆序链表
        ListNode* head2 = reverse(mid);
        // 把head2合并到head链表
        mergeList(head, head2);
    }

    // 从中间分割链表
    ListNode* divide_mid(ListNode* head) {
        // 计算链表总长度
        int size = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            size++;
        }
        // 取中间
        int mid = size / 2 + 1; // 从中间的后面一个节点开始
        cur = head;
        ListNode* prev = cur;
        while (mid--) {
            prev = cur;
            cur = cur->next;
        }
        // 分割链表
        prev->next = nullptr;
        ListNode* midNode = cur;
        return midNode;
    }
    // 逆序链表
    ListNode* reverse(ListNode* mid) {
        ListNode* dump = new ListNode(-1);
        ListNode* src = mid;
        ListNode* dst = dump;
        ListNode* dstNext = dst->next;
        ListNode* srcNext = src->next;
        while (src) {
            dstNext = dst->next;
            srcNext = src->next;
            dst->next = src;
            src->next = dstNext;
            src = srcNext;
        }
        return dump->next;
    }
    // 把head2合并到head链表
    void mergeList(ListNode* head, ListNode* head2) {
        ListNode* cur1 = head;
        ListNode* cur2 = head2;
        ListNode* dump = new ListNode(-1);
        while (cur1 && cur2) {
            ListNode* cur1Next = cur1->next;
            ListNode* cur2Next = cur2->next;
            cur1->next = cur2;
            cur2->next = cur1Next;
            cur1 = cur1Next;
            cur2 = cur2Next;
        }
    }
};

// link : https://leetcode.cn/problems/reorder-list/