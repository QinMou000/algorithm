// 41. 缺失的第一个正数
int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    // 把小于零的数变为 n + 1
    for (auto &e : nums)
        if (e <= 0)
            e = n + 1;
    // 为每一个出现过的正整数在原数组上打标记
    for (int i = 0; i < n; i++) {
        // 哈希值 = abs(元素) - 1
        int index = abs(nums[i]) - 1;
        // 这个 index 必须小于 n
        // 给这个数组中存在过的数（这里已经被映射成了下标）打标记(负号)
        if (index < n)
            nums[index] = -abs(nums[index]);
    }
    for (int i = 0; i < n; i++) {
        // 如果这个下标位置的数不是负号，证明没有打标记，所以这个下标+1对应的数没有出现过
        if (nums[i] > 0)
            return i + 1;
    }
    // 否则返回 n + 1
    return n + 1;
}

// 611. 有效三角形的个数
int triangleNumber(vector<int> &nums) {
    int ans = 0, n = nums.size();
    // l:最短边 r:中间边 i:最长边
    // 最短边与中间边之和大于最长边
    // 那么由于数组有序 从 left + 1 到 right 的所有元素都满足条件
    // else 否则说明短边太小 需要右移 left
    ranges::sort(nums);
    for (int i = n - 1; i >= 2; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (nums[l] + nums[r] > nums[i]) {
                ans += r - l;
                r--;
            } else {
                l++;
            }
        }
    }
    return ans;
}