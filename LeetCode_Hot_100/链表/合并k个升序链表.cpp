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
    ListNode* Merge(ListNode* left, ListNode* right) {
        ListNode* tmp = new ListNode(-1);
        ListNode* cur = tmp;
        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        cur->next = (left == nullptr) ? right : left;
        return tmp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        while (lists.size() >= 2) {
            ListNode* newList = Merge(lists[0], lists[1]); // 归并头两个链表
            lists.erase(lists.begin(), lists.begin() + 2); // 将归并好的两个链表删除
            lists.push_back(newList);       // 将归并好的链表插入数组
        }
        return lists[0];
    }
};


// link : https://leetcode.cn/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked