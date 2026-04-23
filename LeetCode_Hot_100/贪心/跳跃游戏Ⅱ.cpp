class Solution {
public:
    int jump(vector<int>& nums) {
        int step_cnt = 0; // 跳跃次数
        int max_far = 0;  // 目前能跳到的最远位置
        int end = 0;      // 上次跳跃可达范围右边界（下次的最右起跳点）
        // 不用访问最后一个元素
        for (int i = 0; i < nums.size() - 1; i++) {
            // 不断记录当前所能跳到的最远边界
            max_far = max(max_far, i + nums[i]);
            // 到达上次跳跃的最远边界了，必须再跳一次
            if (i == end) {
                end = max_far; // 当前所能跳到的最远边界变为下次起跳的起点
                step_cnt++;    // 起跳次数加一
            }
        }
        return step_cnt;
    }
};

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int position = nums.size() - 1;
//         int steps = 0;
//         while (position > 0) {
//             for (int i = 0; i < position; i++) {
//                 // 去position前面找可以跳到position位置
//                 // 并且距离最远的下标并更新
//                 if (i + nums[i] >= position) {
//                     position = i;
//                     steps++;
//                     break;
//                 }
//             }
//         }
//         return steps;
//     }
// };

// link : https://leetcode.cn/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-100-liked