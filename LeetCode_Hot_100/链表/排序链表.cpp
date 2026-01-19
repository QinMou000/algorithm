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
    ListNode* MergeList(ListNode* left, ListNode* right) {
        ListNode* tmp = new ListNode(-1); // 哨兵头结点
        ListNode* cur = tmp;
        while (left && right) { // 开始归并
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        // 链表跟后面 数组需要while
        cur->next = (left == nullptr) ? right : left;
        return tmp->next; // 剔除哨兵节点
    }
    ListNode* MergeSort(ListNode* head) {
        if (!head || !head->next) { // 如果没有节点或者只有一个节点直接返回
            return head;
        }
        ListNode *fast = head->next /*fast要快一步*/, *slow = head;
        while (fast && fast->next) { // 求出中间节点
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout << slow->val << endl;           // 中间节点
        ListNode* r = MergeSort(slow->next); // 对右边归并
        slow->next = nullptr; // 设定左边归并的终点 最后一次递归会将两部分连接
        ListNode* l = MergeSort(head); // 对左边归并
        return MergeList(r, l);        // 将两边的已经排好序的节点归并
    }
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};

// 快排方式 : TODO


// 第二遍写：
class Solution {
  public:
    ListNode* sortList(ListNode* head) {
        return MergeList(head);
    }
    ListNode* MergeList(ListNode* head) {
        if (!head || !head->next) {
            return head;    // 如果没有节点或者只有一个节点直接返回自身
        }
        // 寻找中间节点
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* right = MergeList(slow->next); // 对右边归并
        slow->next = nullptr; // 设定左边归并的终点 最后一次递归会将两部分连接
        ListNode* left = MergeList(head); // 对左边归并

        return MergeList(left, right); // 将两边的已经排好序的节点归并
    }

    ListNode* MergeList(ListNode* p1, ListNode* p2) {
        ListNode* tmp = new ListNode(-1); // 哨兵节点
        ListNode* cur = tmp;
        while (p1 && p2) {
            if (p1->val > p2->val) {
                cur->next = p2;
                p2 = p2->next;
            } else {
                cur->next = p1;
                p1 = p1->next;
            }
            cur = cur->next;
        }
        cur->next = p1 ? p1 : p2;
        return tmp->next; // 剔除哨兵节点
    }
};
// link : https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked