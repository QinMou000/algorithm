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

// 92. 反转链表 II
class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dump = new ListNode(-1, head);
        ListNode *begin = dump;
        while (--left) {
            begin = begin->next;
        }
        ListNode *end = dump;
        while (right--) {
            end = end->next;
        }
        end = end->next;
        ListNode *cur = begin->next;
        stack<ListNode *> stk;
        while (cur != end) {
            stk.push(cur);
            cur = cur->next;
        }
        while (stk.size()) {
            ListNode *tmp = stk.top();
            stk.pop();
            begin->next = tmp;
            begin = begin->next;
        }
        begin->next = end;
        return dump->next;
    }
};

// 93. 复原 IP 地址
bool check(const string &s, int i, int j) {
    if (j - i > 3 || (j - i > 1 && s[i] == '0'))
        return false;
    return stoi(s.substr(i, j - i)) <= 255;
}
vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<string> ans;
    for (int i = 1; i < n && check(s, 0, i); i++) {
        for (int j = i + 1; j < n && check(s, i, j); j++) {
            for (int k = j + 1; k < n && check(s, j, k); k++) {
                if (check(s, k, n))
                    ans.push_back(s.substr(0, i) + "." + s.substr(i, j - i) + "." + s.substr(j, k - j) + "." +
                                  s.substr(k));
            }
        }
    }
    return ans;
}