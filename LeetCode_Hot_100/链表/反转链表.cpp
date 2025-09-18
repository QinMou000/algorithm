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

// link : https://leetcode.cn/problems/reverse-linked-list/?envType=study-plan-v2&envId=top-100-liked