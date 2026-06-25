class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // left 表示最左边为零的数
        // right 表示已经遍历的最后一个数 判断是否为零即可
        int left = 0, right = 0;
        while (right < n) {
            if (nums[right] != 0)
                swap(nums[left++], nums[right]);
            right++;
        }
    }
};


// 第二遍写：
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // left和right分别指向下一个要放非零数的位置，不为零的位置
        // 我们就不断把非零元素往前挪，零元素自然就放到了最后
        int left, right;
        left = right = 0;
        while (right < nums.size()) {
            if (nums[right])
                swap(nums[left++], nums[right]);
            right++;
        }
    }
};

// link : https://leetcode.cn/problems/move-zeroes/?envType=study-plan-v2&envId=top-100-liked