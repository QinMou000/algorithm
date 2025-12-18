// // class Solution {
// // public:
// //     int countTarget(vector<int>& scores, int target) {
// //         unordered_map<int, int> cnt;
// //         for (auto& e : scores)
// //             cnt[e]++;
// //         return cnt[target];
// //     }
// // };

class Solution {
public:
    // 好丑陋的写法
    int countTarget(vector<int>& scores, int target) {
        if (scores.size() == 0)
            return 0;
        // 二分找出左右边界相减
        int n = scores.size();
        int left = 0, right = n - 1;
        int begin, end;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (scores[mid] > target)
                right = mid - 1;
            else if (scores[mid] < target)
                left = mid + 1;
            else {
                // 此时mid位置和tar相等
                // 只需向左右扩展边界即可
                begin = mid, end = mid;
                // 此时左边界下标必须大于前一次二分的左边界下标
                while (begin > left && target == scores[begin - 1])
                    begin--; // 如果左边的位置满足两个条件 再减减
                // 同样 此时右边界下标必须小于前一次二分的右边界下标
                while (end < right && target == scores[end + 1])
                    end++;
                break;
            }
        }
        if (scores[begin] != target || scores[end] != target)
            return 0;
        return end - begin + 1;
    }
};

// class Solution {
// public:
//     int lowerbound(vector<int>& scores, int target) {
//         int n = scores.size();
//         int left = 0, right = n - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             cout << scores[mid] << endl;
//             if (scores[mid] < target)
//                 left = mid + 1; // 先动左边
//             else
//                 right = mid - 1;
//         }
//         return left; // 这个left是左边界
//     }
//     int countTarget(vector<int>& scores, int target) {
//         // 二分找出左右边界相减
//         int begin = lowerbound(scores, target);
//         int end = lowerbound(scores, target + 1) - 1;
//         return end - begin + 1;
//     }
// };

// link : https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p