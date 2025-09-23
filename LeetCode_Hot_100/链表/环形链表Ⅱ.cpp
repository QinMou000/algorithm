/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* detectCycle(ListNode* head) {
//         // ListNode* fast = head;
//         // ListNode* low = head;
//         // while (fast && fast->next && low) {
//         //     fast = fast->next->next;
//         //     low = low->next;
//         //     if (fast == low)
//         //         return fast;
//         // }
//         // return nullptr;
//         // 这种快慢指针只能判断是否有环 不能判断入环位置
//         unordered_set<ListNode*> hash;
//         ListNode* cur = head;
//         while (cur) {
//             if (hash.count(cur) > 0)
//                 return cur;
//             hash.insert(cur);
//             cur = cur->next;
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* low = head;
        ListNode* ptr = head;
        while (fast && fast->next && low) {
            fast = fast->next->next;
            low = low->next;
            if (fast == low) {
                // 当快慢指针相遇时 再用一个指针从头开始和fast一起走
                while (fast != ptr) {
                    fast = fast->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

// link : https://leetcode.cn/problems/linked-list-cycle-ii/description/?envType=study-plan-v2&envId=top-100-liked 