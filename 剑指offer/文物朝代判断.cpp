// class Solution {
// public:
//     int patition(vector<int>& nums, int left, int right) {
//         int l = left, r = right;
//         int x = nums[left];
//         while (l < r) {
//             while (l < r && nums[r] >= x)
//                 r--;
//             while (l < r && nums[l] <= x)
//                 l++;
//             swap(nums[l], nums[r]);
//         }
//         swap(nums[left], nums[l]);
//         return l;
//     }

//     void QuickSort(vector<int>& nums, int left, int right) {
//         if (left > right)
//             return;
//         int piovt = patition(nums, left, right);

//         QuickSort(nums, left, piovt - 1);
//         QuickSort(nums, piovt + 1, right);
//     }

//     bool checkDynasty(vector<int>& places) {
//         QuickSort(places, 0, places.size() - 1); // 升序排序

//         int zero_cnt = 0;
//         for (int i = 0; i < places.size() - 1; i++) {
//             if (places[i] == 0) {
//                 zero_cnt++; // 对 0计数器不断累加
//                 continue;
//             }
//             if (places[i + 1] - places[i] == 0)
//                 return false; // 有重复元素直接返回false
//             if (places[i + 1] - places[i] != 1) {
//                 // 对计数器减去对应的值
//                 zero_cnt -= places[i + 1] - places[i] - 1;
//             }
//         }

//         return zero_cnt >= 0;
//     }
// };

class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        unordered_set<int> map;
        int Max = 0, Min = 14;
        for (auto& e : places) {
            if (e == 0)
                continue;
            Max = max(e, Max);
            Min = min(e, Min);
            if (map.find(e) != map.end())
                return false; // 有重复元素返回false
            map.insert(e);
        }
        cout << Max << " " << Min << endl;
        return Max - Min < 5; // max - min 最多就是4 不可能大于4
    }
};

// link : https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/description/