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