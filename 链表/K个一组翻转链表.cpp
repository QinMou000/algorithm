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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            cur = cur->next;
            n++;
        }
        int cnt = n / k;
        int time = k;
        // 哨兵节点
        ListNode* dump = new ListNode(-1);
        ListNode* newHead = dump;
        cur = head;
        while (cnt--) { // 翻转 cnt 次
            // 头插法逆序
            ListNode* prev = cur;
            time = k; // 记住更新time
            while (time--) {
                cout << cur->val << endl;
                ListNode* Next = cur->next;
                cur->next = newHead->next;
                newHead->next = cur;
                cur = Next;
            }
            newHead = prev;
        }
        newHead->next = cur; // 接上后面没有翻转的节点
        return dump->next;
    }
};

// link : https://leetcode.cn/problems/reverse-nodes-in-k-group/description/