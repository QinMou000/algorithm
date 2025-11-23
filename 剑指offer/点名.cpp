// class Solution {
// public:
//     int takeAttendance(vector<int>& records) {
//         int n = records.size(), sum = 0;
//         for (int i = 0; i <= n; i++)
//             sum += i;

//         int arrSum = 0;
//         for (auto& e : records)
//             arrSum += e;
//         return sum - arrSum;
//     }
// };

// class Solution {
// public:
//     int takeAttendance(vector<int>& records) {
//         for (int i = 0; i < records.size(); i++)
//             if (records[i] != i)
//                 return i;
//         return records.size();
//     }
// };

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int n = records.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (records[mid] != mid) {
                // 左边数组有问题
                right = mid - 1;
            } else {
                // 问题出在右边数组
                left = mid + 1;
            }
        }
        // 有问题指 下标和值对不上
        // cout << left << right << endl;
        return left;
    }
};

// link : https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p