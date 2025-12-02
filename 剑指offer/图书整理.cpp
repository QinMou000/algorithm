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

// // 反转链表
// // 时间 O(n)
// // 空间 O(n)
// class Solution {
// public:
//     vector<int> reverseBookList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* cur = head;
//         ListNode* next = nullptr;
//         while (cur) {
//             next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }
//         vector<int> ans;
//         while (prev) {
//             ans.push_back(prev->val);
//             prev = prev->next;
//         }
//         return ans;
//     }
// };

// // 递归
// // 时间 O(n)
// // 空间 O(n) 函数栈帧
// class Solution {
// public:
//     vector<int> reverseBookList(ListNode* head) {
//         recursion(head);
//         return ans;
//     }

// private:
//     vector<int> ans;
//     void recursion(ListNode* head) {
//         if (!head)
//             return;
//         recursion(head->next);
//         ans.push_back(head->val);
//     }
// };

// 辅助栈
// 时间 O(n)
// 空间 O(n)
class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        vector<int> ans;
        stack<ListNode*> stk;
        ListNode* cur = head;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        while (!stk.empty()) {
            ans.push_back(stk.top()->val);
            stk.pop();
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/?envType=problem-list-v2&envId=XApvNy3p