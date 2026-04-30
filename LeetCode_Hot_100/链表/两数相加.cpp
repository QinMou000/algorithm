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
    void Push_Back(ListNode*& head, int x) {
        ListNode* cur = new ListNode(x);
        if (!head) {
            head = cur;
            return;
        }
        ListNode* tail = head;
        while (tail->next) // 找尾
            tail = tail->next;
        tail->next = cur;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // 遍历链表后 将相加后的节点头插
        int x;
        ListNode* head = nullptr;
        while (l1 && l2) {
            x = l1->val + l2->val + carry;
            carry = 0;
            if (x > 9) { // 进位处理
                carry = 1;
                x %= 10;
            }
            cout << x << endl;
            Push_Back(head, x); // 头插
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            x = l1->val + carry;
            carry = 0;
            if (x > 9) { // 进位处理
                carry = 1;
                x %= 10;
            }
            cout << x << endl;
            Push_Back(head, x); // 头插
            l1 = l1->next;
        }
        while (l2) {
            x = l2->val + carry;
            carry = 0;
            if (x > 9) { // 进位处理
                carry = 1;
                x %= 10;
            }
            cout << x << endl;
            Push_Back(head, x); // 头插
            l2 = l2->next;
        }
        if (carry == 1)
            Push_Back(head, carry); // 头插
        return head;
    }
};

// 第二遍写
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(-1);
        ListNode* cur = dump;
        int sum = 0;
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            int x = sum % 10;
            ListNode* newNode = new ListNode(x);
            cur->next = newNode;
            cur = newNode;
            sum /= 10; // 算作下一次的进位
        }
        if (sum)
            cur->next = new ListNode(sum);
        return dump->next;
    }
};

// link : https://leetcode.cn/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-100-liked