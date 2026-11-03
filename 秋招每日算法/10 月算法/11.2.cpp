// 61. 旋转链表

ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
        return nullptr;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        n++;
        cur = cur->next;
    }
    cur->next = head; // 串成环形链表
    int step = n - k % n;
    while (step--) {
        cur = cur->next;
    }
    ListNode *NewHead = cur->next;
    cur->next = nullptr;

    return NewHead;
}

// 3. 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> cnt;
    int n = s.size();
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        cnt[s[r]]++;
        while (cnt[s[r]] > 1) {
            cnt[s[l++]]--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}