class Solution {
public:
    int maxArea(vector<int>& height) {
        // int ans = 0;
        // for (int i = 0; i < height.size(); i++)
        //     for (int j = i + 1; j < height.size(); j++) {
        //         int contain = min(height[i], height[j]) * (j - i);
        //         if (contain > ans)
        //             ans = contain;
        //     }
        // return ans;
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int contain = (right - left) * min(height[left], height[right]);
            if (contain > ans)
                ans = contain;
            height[left] > height[right] ? right-- : left++;
        }
        return ans;
    }
};
// 第二遍写
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;
        while (left < right) {
            int sum = min(height[left], height[right]) * (right - left);
            ans = sum > ans ? sum : ans;
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked