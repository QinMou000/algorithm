#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 1004. 最大连续1的个数 III
int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;
    int zero_cnt = 0;
    for (int l = 0, r = 0; r < n; r++) {
        if (nums[r] == 0)
            zero_cnt++;
        while (zero_cnt > k) {
            if (nums[l++] == 0)
                zero_cnt--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// 9.12

// 42. 接雨水
int trap(vector<int> &height) {
    int n = height.size();
    int soild_cnt = 0, max_h = 0;
    for (auto e : height) {
        max_h = max(max_h, e);
        soild_cnt += e;
    }
    int l = 0, r = n - 1;
    int cur_h = 1, sum = 0;
    while (l <= r) {
        while (l <= r && height[l] < cur_h)
            l++;
        while (l <= r && height[r] < cur_h)
            r--;
        sum += r - l + 1;
        cur_h++;
    }
    return sum - soild_cnt;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 25. K 个一组翻转链表
class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int cnt = k;
        stack<ListNode *> stk;
        ListNode *cur = head;
        ListNode *ddump = new ListNode(-1); // 答案的哨兵节点
        ListNode *ttail = ddump;            // 答案的尾节点
        while (cur) {
            stk.push(cur);
            cur = cur->next;
            if (stk.size() == k) {
                while (stk.size()) {
                    ListNode *top = stk.top();
                    stk.pop();
                    ttail->next = top;
                    ttail = ttail->next;
                }
                ttail->next = nullptr;
            }
        }
        // 头插
        while (stk.size()) {
            cur = stk.top();
            stk.pop();

            cur->next = nullptr;
            ListNode *next = ttail->next;
            ttail->next = cur;
            cur->next = next;
        }
        return ddump->next;
    }
};

// 239. 滑动窗口最大值
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
        pq.push(make_pair(nums[i], i));
    ans.push_back(pq.top().first);
    for (int i = k; i < nums.size(); i++) {
        pq.push(make_pair(nums[i], i));

        while (pq.top().second <= i - k)
            pq.pop();

        ans.push_back(pq.top().first);
    }

    return ans;
}

// 76. 最小覆盖子串
string minWindow(string s, string t) {
    unordered_map<char, int> cnt;
    int kinds = 0;
    for (auto c : t) {
        if (cnt[c] == 0)
            kinds++;
        cnt[c]++;
    }
    int ans_pos = 0, ans_len = INT_MAX;
    for (int l = 0, r = 0; r < s.size(); r++) {
        if (--cnt[s[r]] == 0) // 入窗口
            kinds--;

        while (kinds == 0) {
            if (ans_len > r - l + 1) {
                ans_pos = l;
                ans_len = r - l + 1;
            }
            if (++cnt[s[l++]] > 0) // 出窗口
                kinds++;
        }
    }
    return ans_len == INT_MAX ? "" : s.substr(ans_pos, ans_len);
}