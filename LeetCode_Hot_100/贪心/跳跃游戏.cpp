class Solution {
public:
    bool canJump(vector<int>& nums) {
        int LastPos = nums.size() - 1;
        for (int i = LastPos; i >= 0; i--) {
            // 如果当前位置(i)加上当前位置能走的步数大于LastPos
            // 就代表可以从当前位置走到lastpos
            // 继而将lastpos更新为i 再次向前遍历
            if (i + nums[i] >= LastPos)
                LastPos = i;
        }
        return LastPos == 0;
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         // 1. 定义变量 k：记录**当前能到达的最远位置**
//         int k = 0;
        
//         // 2. 遍历数组中的每一个位置 i
//         for (int i = 0; i < nums.size(); i++) {
            
//             // 3. 核心判断：如果当前位置 i 超过了能到达的最远位置 k
//             // 说明永远到不了 i 这个位置，直接返回 false
//             if (i > k) return false;
            
//             // 4. 更新最远能到达的位置
//             // 取「原来的最远 k」和「当前位置i能跳到的最远 i+nums[i]」的最大值
//             k = max(k, i + nums[i]);
//         }
        
//         // 5. 遍历完所有位置都没返回false，说明能到达最后一个位置
//         return true;
//     }
// };

// link : https://leetcode.cn/problems/jump-game/?envType=study-plan-v2&envId=top-100-liked