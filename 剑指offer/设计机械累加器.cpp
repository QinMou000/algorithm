class Solution {
public:
    // 递归
    int mechanicalAccumulator(int target) {
        target && (target += mechanicalAccumulator(target - 1));
        return target; // 如果 target 为 0 就直接短路了
    }
};

// class Solution {
// public:
//     // 利用公式 1 到 n 的和 : (n + 1)n/2
//     int mechanicalAccumulator(int target) {
//         bool arr[target + 1][target];
//         return sizeof(arr) / 2;
//     }
// };

// link : https://leetcode.cn/problems/qiu-12n-lcof/description/?envType=problem-list-v2&envId=XApvNy3p