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
// class Solution {
// public:
//     // 将数据存到 string 里面判断
//     bool isPalindrome(ListNode* head) {
//         ListNode* cur = head;
//         string s;
//         while (cur) {
//             s += to_string(cur->val);
//             cur = cur->next;
//         }
//         string tmp = s;
//         reverse(s.begin(), s.end());
//         if (tmp == s)
//             return true;
//         return false;
//     }
// };

class Solution {
public:
    // 快慢指针 找中点 反转后面的链表 从两边遍历
    ListNode* FindMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* low = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            low = low->next;
        }
        return low;
    }
    ListNode* Reverse(ListNode* head) {
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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        ListNode* mid = FindMid(head);
        ListNode* tail = Reverse(mid);
        while (head != nullptr && tail != nullptr) {
            if (head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};

// link : https://leetcode.cn/problems/palindrome-linked-list/?envType=study-plan-v2&envId=top-100-liked
