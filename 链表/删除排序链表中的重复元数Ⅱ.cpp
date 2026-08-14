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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dump = new ListNode(-1, head);
        ListNode *l = dump;
        ListNode *r = dump->next;
        // 夹在 (l, r] 之间的Node删掉
        while (r && r->next) {
            if (r->next && r->val == r->next->val) {
                while (r->next && r->val == r->next->val) {
                    r = r->next;
                }
                deleteFromTo(l, r);
                r = l->next;
            } else {
                l = r;
                r = r->next;
            }
        }
        return dump->next;
    }
    void deleteFromTo(ListNode *begin, ListNode *end) {
        ListNode *Next = end->next;
        end->next = nullptr;

        ListNode *de = begin->next;

        begin->next = Next;
        while (de) {
            ListNode *tmp = de;
            de = de->next;
            delete tmp;
        }
    }
};

// link :
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan-v2&envId=top-interview-150