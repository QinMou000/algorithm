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
    ListNode* Head;
    Solution(ListNode* head) { Head = head; }

    int getRandom() {
        ListNode* cur = Head;
        int ans = 0;
        int count = 1;
        // 链表只有一个节点 第一个节点100%被选中
        // 两个节点 第一个节点 50%被选中 第二个50%
        // 三个节点 此时 count=3 每一个节点被选中概率都为33%
        while (cur) {
            if (rand() % count == 0)
                ans = cur->val;
            count++;
            cur = cur->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// link : https://leetcode.cn/problems/linked-list-random-node/description/