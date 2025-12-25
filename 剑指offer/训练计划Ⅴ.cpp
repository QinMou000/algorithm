/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, int> map;
        while (headA) {
            map[headA]++;
            headA = headA->next;
        }
        while (headB) {
            if (map[headB] > 0)
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

// 除此之外的解法还有:
// 1、双指针遍历算长度 长的链表先走 然后一起走 最后相遇
// 2、两个指针先走各自的链表 一遍后 再走对方的链表 最后相遇

// link : https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/description/?envType=problem-list-v2&envId=XApvNy3p