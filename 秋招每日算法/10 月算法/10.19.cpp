#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 会议室 II
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &interval : intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << sol.minMeetingRooms(intervals1) << endl; // expect 2

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << sol.minMeetingRooms(intervals2) << endl; // expect 1

    vector<vector<int>> intervals3 = {};
    cout << sol.minMeetingRooms(intervals3) << endl; // expect 0
    return 0;
}

// 3. 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> cnt;
    for (int l = 0, r = 0; r < s.size(); r++) {
        cnt[s[r]]++;
        while (cnt[s[r]] > 1) {
            cnt[s[l++]]--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// 692. 前K个高频单词
static bool cmp(const pair<string, int> p1, const pair<string, int> p2) {
    return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
}
vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> cnt;
    for (auto &str : words)
        cnt[str]++;

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&cmp)> pq(cmp);

    for (auto it : cnt) {
        pq.push(it);
        if (pq.size() > k)
            pq.pop();
    }
    vector<string> ans;
    while (pq.size()) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 21. 合并两个有序链表
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dump = new ListNode(-1);
    ListNode *cur = dump;
    while (list1 && list2) {
        if (list1->val > list2->val) {
            cur->next = list2;
            list2 = list2->next;
        } else {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    if (list1)
        cur->next = list1;
    if (list2)
        cur->next = list2;
    return dump->next;
}

// 334. 递增的三元子序列
bool increasingTriplet(vector<int> &nums) {
    // first : 最小的数 second : 第二小的数
    // 一边更新 first second 一边找 有没有数字 n > second
    int first = INT_MAX, second = INT_MAX;
    for (int n : nums) {
        if (n <= first)
            first = n;
        else if (n <= second)
            second = n;
        else
            return true;
    }
    return false;
}