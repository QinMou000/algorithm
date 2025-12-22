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
    // 经典三指针倒序链表
    ListNode* trainningPlan(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next; // 先保存后一个节点
            cur->next = prev; // 将当前节点指向prev完成反转
            prev = cur;       // 更新prev
            cur = next;       // 更新cur
        }
        return prev; // 反转后的链表头节点就是prev
    }
};

// link : https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/description/?envType=problem-list-v2&envId=XApvNy3p