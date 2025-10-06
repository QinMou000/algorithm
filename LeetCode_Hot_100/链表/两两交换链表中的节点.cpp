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
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy = new ListNode(-1, head); // 添加哨兵节点
//         ListNode* cur = dummy;

//         while (cur->next && cur->next->next) {
//             ListNode* n1 = cur->next;
//             ListNode* n2 = cur->next->next; // 给要交换的节点赋值

//             cur->next = n2; // 交换位置
//             n1->next = n2->next;
//             n2->next = n1;

//             cur = n1; // 迭代
//         }

//         return dummy->next;
//     }
// };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next); // head的下一个节点指向 newHead-next 交换完成的链表
        newHead->next = head;                  // 将 head 和 newHead 位置交换
        return newHead;
    }
};

//  link : https://leetcode.cn/problems/swap-nodes-in-pairs/?envType=study-plan-v2&envId=top-100-liked
