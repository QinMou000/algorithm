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
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* head = new ListNode(-1);
//         ListNode* cur = head;
//         while (list1 && list2) {
//             if (list1->val > list2->val) {
//                 cur->next = list2;
//                 list2 = list2->next;
//             } else {
//                 cur->next = list1;
//                 list1 = list1->next;
//             }
//             cur = cur->next;
//         }
//         while (list1) {
//             cur->next = list1;
//             list1 = list1->next;
//             cur = cur->next;
//         }
//         while (list2) {
//             cur->next = list2;
//             list2 = list2->next;
//             cur = cur->next;
//         }
//         return head->next;
//     }
// };

class Solution {
public:
    // 递归写法
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 如果 list1 list2 两个任意为空 直接返回
        if (!list1)
            return list2;
        else if (!list2)
            return list1;
        else if (list1->val > list2->val) {
            // list2 的下一个就等于 list1 和 list2->next 两个链表合并的结果
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        } else {
            // list1 的下一个就等于 list2 和 list1->next 两个链表合并的结果
            list1->next = mergeTwoLists(list2, list1->next);
            return list1;
        }
        // 泰妙啦~~~~~
    }
};

// link : https://leetcode.cn/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-100-liked