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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // ListNode* Head = new ListNode(-1);
//         // Head->next = head; // 可以添加哨兵节点 就不需要对头节点置空判断了
//         ListNode* cur = head;
//         if (!cur->next)
//             return nullptr;
//         int len = 0;
//         while (cur) { // 算出长度
//             len++;
//             cur = cur->next;
//         }
//         int cnt = len - n;
//         cur = head;
//         ListNode* prev = nullptr;
//         while (cnt--) {
//             prev = cur;
//             cur = cur->next;
//         } // cur 就是要删除的节点
//         if (!prev)
//             return cur->next;
//         else
//             prev->next = cur->next;
//         delete cur;
//         return head;
//     }
// };

// 双指针 fast slow fast 比 slow 快 n 个节点
// 当 fast 到尾部了 slow 就是要删除的节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next)
            return nullptr;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = head;
        ListNode* slow = dummy;
        while (n--)
            fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow 的下一个节点就是要删除的节点
        slow->next = slow->next->next;
        return dummy->next;
    }
};
// 不管是先算长度 双指针 还是用栈 本质都是为了得到倒数第 n 个节点的前驱节点

// link : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-100-liked