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
//     // 哈希
//     bool hasCycle(ListNode* head) {
//         unordered_set<ListNode*> hash;
//         ListNode* cur = head;
//         while (cur) {
//             if (hash.find(cur) != hash.end())
//                 return true;
//             hash.insert(cur);
//             cur = cur->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    // 快慢指针
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* low = head;
        while (fast != nullptr && fast->next != nullptr && low != nullptr) {
            fast = fast->next->next;
            low = low->next;
            if (fast == low)
                return true;
        }
        return false;
    }
};

// link : https://leetcode.cn/problems/linked-list-cycle/?envType=study-plan-v2&envId=top-100-liked 