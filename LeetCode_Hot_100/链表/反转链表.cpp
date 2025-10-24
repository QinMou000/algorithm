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

// 构建一个新链表头插
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *ans = nullptr;
//         ListNode *cur = head;
//         while(cur)
//         {
//             ListNode *tmp = new ListNode(cur->val);
//             // 头插
//             tmp->next = ans;
//             ans = tmp;
//             cur = cur->next;
//         }
//         return ans;
//     }
// };

// 三指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* Prev = nullptr;
        ListNode* Cur = head;
        ListNode* Next = nullptr;
        while (Cur) {
            // 保存下一个节点
            Next = Cur->next;
            // 改变指针指向
            Cur->next = Prev;
            // 往后迭代
            Prev = Cur;
            Cur = Next;
        }
        return Prev;
    }
};

// // 递归写法
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // 链表为空时直接返回，链表不为空则到返回最后一个节点
//         if(!head || !head->next) {
//             return head;
//         }
//         // newHead先指向最后一个节点，注意此时参数是倒数第二个节点
//         // 这一步很精妙，每一次newHead都是指向空指针（链表为空）或保留在原链表中的最后一个节点（链表不空），作用就是返回新的头结点
//         ListNode* newHead = reverseList(head->next);
//         // 最后一个节点指向倒数第二个节点
//         head->next->next = head;
//         // 倒数第二个节点的下一节点置空。此时倒数第三个节点仍指向倒数第二个节点，下一次递归中将倒数第二个节点下一节点指向倒数第三个节点，不断重复这一过程
//         head->next = nullptr;
//         return newHead;
//     }
// };

// link : https://leetcode.cn/problems/reverse-linked-list/?envType=study-plan-v2&envId=top-100-liked