/*
 * @Author: wang-qin928 2830862261@qq.com
 * @Date: 2025-12-23 18:44:47
 * @LastEditors: wang-qin928 2830862261@qq.com
 * @LastEditTime: 2025-12-23 18:44:50
 * @FilePath: \algorithm\贪心\分发糖果.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 时间 O(n)
// 空间 O(n)
class Solution {
public:
    // 分别对一个孩子左右两边规则进行判断 最后取两次判断的最大值
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        for (int l = 0; l < n - 1; l++) {
            if (ratings[l] < ratings[l + 1])
                left[l + 1] = left[l] + 1;
        }
        int ans = 0;
        vector<int> right(n, 1);
        for (int r = n - 1; r > 0; r--) {
            if (ratings[r - 1] > ratings[r])
                right[r - 1] = right[r] + 1;
        }
        // for (int i = 0; i < n; i++)
        //     cout << left[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++)
        //     cout << right[i] << " ";
        for (int i = 0; i < n; i++)
            ans += max(left[i], right[i]);
        return ans;
    }
};

// link :https://leetcode.cn/problems/candy/description/