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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        int len = 0;
        ListNode* cur = head;
        // 算总长度
        while (cur) {
            cur = cur->next;
            len++;
        }
        // 计算正数在第几个位置
        int res = len - cnt;
        cur = head;
        while (res--)
            cur = cur->next;
        return cur;
    }
};

// link : https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/?envType=problem-list-v2&envId=XApvNy3p