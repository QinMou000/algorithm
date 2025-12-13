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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
            return head->next;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur->val != val) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        return head;
    }
};

// link : https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/?envType=problem-list-v2&envId=XApvNy3p