#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    // 2. 两数相加
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dump = new ListNode(-1);
        ListNode *node = dump;
        int car = 0;
        while (l1 || l2) {
            int cur = 0;
            if (l1) {
                cur += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                cur += l2->val;
                l2 = l2->next;
            }
            cur += car;
            car = cur / 10;
            cur %= 10;
            node->next = new ListNode(cur);
            node = node->next;
        }
        if (car)
            node->next = new ListNode(car);
        return dump->next;
    }

    // 19. 删除链表的倒数第 N 个结点
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dump = new ListNode(-1, head);
        ListNode *fast = dump;
        ListNode *prev = dump;
        ListNode *slow = dump;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = slow->next;

        return dump->next;
    }

    // 82. 删除排序链表中的重复元素 II
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dump = new ListNode(-1, head);
        ListNode *cur = dump;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                while (cur->next->next &&
                       cur->next->val == cur->next->next->val) {
                    cur->next = cur->next->next;
                }
                cur->next = cur->next->next;
            } else
                cur = cur->next;
        }
        return dump->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
