// 69. x 的平方根
int mySqrt(int x) {
    int l = 0, r = x;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

// 560. 和为 K 的子数组
int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map; // 前缀和 -> 出现次数
    int prev = 0;                // 前缀和
    int ans = 0;
    map[0] = 1;
    for (int i = 0; i < n; i++) {
        prev += nums[i];
        if (map.count(prev - k))
            ans += map[prev - k];
        map[prev]++;
    }
    return ans;
}
// 470. 用 Rand7() 实现 Rand10()
int rand10() {
    while (1) {
        int num = (rand7() - 1) * 7 + rand7();
        if (num <= 40)
            return num % 10 + 1;
        // num 在 41 - 49 之间
        num = (num - 41) * 7 + rand7();
        if (num <= 60)
            return num % 10 + 1;
        // num 在 61 - 63 之间
        num = (num - 61) * 7 + rand7();
        if (num <= 20)
            return num % 10 + 1;
        // 最后只可能舍弃掉一个数 循环次数大大减少
    }
    return -1;
}