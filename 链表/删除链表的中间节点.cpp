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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;
        ListNode *fast = head, *slow = head;
        ListNode* prev = nullptr;
        ListNode* next = slow->next;
        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
            next = slow->next;
        }
        prev->next = next;
        // slow就是要删除的节点
        cout << slow->val << endl;
        return head;
    }
};

// link : https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/description/