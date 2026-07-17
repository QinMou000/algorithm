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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        // 简单的复制粘贴
        ListNode *cur = list1;
        ListNode *node1 = nullptr;
        ListNode *node2 = nullptr;
        ListNode *prev = nullptr;
        while (a-- && cur) {
            prev = cur;
            cur = cur->next;
        }
        node1 = prev;

        cur = list1;
        while (b-- && cur) {
            prev = cur;
            cur = cur->next;
        }
        node2 = cur;

        node1->next = list2;

        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = node2->next;
        return list1;
    }
};

// link : https://leetcode.cn/problems/merge-in-between-linked-lists/description/