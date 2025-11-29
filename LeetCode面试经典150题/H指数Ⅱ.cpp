class Solution {
public:
    int hIndex(vector<int>& arr) {
        // 看不懂就把这个带进去算一遍[0,1,3,5,6]
        int n = arr.size();
        // 若是arr[i] >= 剩余的n - i个论文
        // 就说明剩余的 n - i 个论文引用次数
        // 全是大于等于 n - i 的 直接返回
        for (int i = 0; i < n; i++)
            if (arr[i] >= n - i)
                return n - i;
        return 0;
    }
};

// link : https://leetcode.cn/problems/h-index-ii/