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

// 第二遍写：
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        // 算链表长度
        while (cur) {
            cur = cur->next;
            n++;
        }
        // 把链表的一半压栈
        int cnt = n / 2;
        stack<ListNode*> stk;
        cur = head;
        while (cnt--) {
            stk.push(cur);
            cur = cur->next;
        }
        if (n % 2 == 1)
            cur = cur->next;
        // 从中间开始向后与栈顶元素对比
        while (!stk.empty() && cur) {
            ListNode* tmp = stk.top();
            stk.pop();
            if (tmp->val != cur->val) {
                return false;
            }
            cur = cur->next;
        }
        return true;
    }
};

// link : https://leetcode.cn/problems/palindrome-linked-list/?envType=study-plan-v2&envId=top-100-liked
