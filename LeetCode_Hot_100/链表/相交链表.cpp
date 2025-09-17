// // 让长的先走差值 然后一起走 最后在结果相遇
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         int lenA = 0, lenB = 0;
//         ListNode* cur = headA;
//         while (cur) {
//             cur = cur->next;
//             lenA++;
//         }
//         cur = headB;
//         while (cur) {
//             cur = cur->next;
//             lenB++;
//         }
//         ListNode* cur1 = headA;
//         ListNode* cur2 = headB;
//         if (lenA - lenB > 0) {
//             int x = lenA - lenB;
//             while (x--)
//                 cur1 = cur1->next;
//             while (cur1 != cur2) {
//                 cur1 = cur1->next;
//                 cur2 = cur2->next;
//             }
//         } else {
//             int x = lenB - lenA;
//             while (x--)
//                 cur2 = cur2->next;
//             while (cur1 != cur2) {
//                 cur1 = cur1->next;
//                 cur2 = cur2->next;
//             }
//         }
//         return cur1;
//     }
// };

// // 两个指针都把对方走的路走一遍 之后相遇
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         ListNode* cur1 = headA;
//         ListNode* cur2 = headB;
//         while (cur1 != cur2) {
//             cur1 = cur1 ? cur1->next : headB;
//             cur2 = cur2 ? cur2->next : headA;
//         }
//         return cur1;
//     }
// };

// hash
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> map;
        ListNode* cur = headA;
        while (cur) {
            map.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while (cur) {
            if (map.find(cur) != map.end()) // 找到了
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};

// link : https://leetcode.cn/problems/intersection-of-two-linked-lists/?envType=study-plan-v2&envId=top-100-liked