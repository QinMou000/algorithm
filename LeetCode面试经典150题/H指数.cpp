// // 时间 O(n^2)
// // 空间 O(1)
// class Solution {
// public:
//     // 暴力
//     int hIndex(vector<int>& arr) {
//         int ans = 0;
//         for (int i = 0; i <= arr.size(); i++) {
//             // 假设答案是i
//             int cnt = 0;
//             for (int j = 0; j < arr.size(); j++) {
//                 if (arr[j] >= i)
//                     cnt++;
//             }
//             if (cnt >= i)
//                 ans = max(i, ans);
//         }
//         return ans;
//     }
// };

// // 时间 O(nlogn)
// // 空间 O(1)
// class Solution {
// public:
//     int hIndex(vector<int>& arr) {
//         // 排序+遍历
//         sort(arr.begin(), arr.end());
//         // 看不懂就把这个带进去算一遍[0,1,3,5,6]
//         int n = arr.size();
//         // 若是arr[i] >= 剩余的n - i个论文
//         // 就说明剩余的 n - i 个论文引用次数
//         // 全是大于等于 n - i 的 直接返回
//         for (int i = 0; i < n; i++)
//             if (arr[i] >= n - i)
//                 return n - i;
//         return 0;
//     }
// };

// // 时间 O(nlogn)
// // 空间 O(1)
// class Solution {
// public:
//     int hIndex(vector<int>& arr) {
//         // 二分
//         // 结果最大就是数组大小 即发表论文的篇数
//         int left = 0, right = arr.size();
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             int cnt = 0;
//             for (int i = 0; i < arr.size(); i++)
//                 if (arr[i] >= mid)
//                     cnt++;
//             if (mid <= cnt) // 满足条件尝试更大的结果
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return right; // 返回最后一个满足条件的值也就是right
//     }
// };

// 时间 O(n)
// 空间 O(1)
class Solution {
public:
    int hIndex(vector<int>& arr) {
        // 计数
        int n = arr.size();
        vector<int> cnt(n + 1);
        for (auto& e : arr)
            cnt[min(n, e)]++; // 统计计数
        int sum = 0;
        for (int i = n;; i--) {
            sum += cnt[i]; // 将大于等于 i 次计数的论文数累加
            if (sum >= i)
                return i;
        }
    }
};

// link : https://leetcode.cn/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

// 豆包老师题解 : https://www.doubao.com/chat/31824991281264642