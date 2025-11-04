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
        if (!head || !head->next) // 如果没有节点或者只有一个节点直接返回
            return head;
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
    ListNode* sortList(ListNode* head) { return MergeSort(head); }
};

// 快排方式 : TODO

// link : https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked