class Solution {
public:
    int dismantlingAction(string arr) {
        // 滑动窗口
        int n = arr.size();
        int cnt[1000] = {0};
        int ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            int index = arr[right] - ' ';
            // 进窗口
            cnt[index]++;
            // 判断
            while (cnt[index] >= 2) {
                // 出窗口
                cnt[arr[left] - ' ']--;
                left++;
            }
            ans = max(ans, right - left + 1);
            // 更新结果
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/description/?envType=problem-list-v2&envId=XApvNy3p