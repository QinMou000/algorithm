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