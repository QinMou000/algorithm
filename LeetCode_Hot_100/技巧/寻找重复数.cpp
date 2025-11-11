class Solution
{
public:
    // int findDuplicate(vector<int>& nums) {
    //     int fast = 0, slow = 0;
    //     do {
    //         fast = nums[nums[fast]];
    //         slow = nums[slow];
    //     } while (fast != slow);
    //     slow = 0;
    //     while (fast != slow) {
    //         fast = nums[fast];
    //         slow = nums[slow];
    //     }
    //     return slow;
    // }

    // Floyd 判圈算法 判断一个链表是否有环 并且找到环的入口
    // 环形链表Ⅱ link : https://leetcode.cn/problems/linked-list-cycle-ii/description/
    int findDuplicate(vector<int> &nums)
    {
        int fast = nums[nums[0]], slow = nums[0];
        while (fast != slow)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

// link : https://leetcode.cn/problems/find-the-duplicate-number/description/?envType=study-plan-v2&envId=top-100-liked