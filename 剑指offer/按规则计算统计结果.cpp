class Solution {
public:
    // 前后缀积
    // 时间 O(N)
    // 空间 O(2 * N)
    vector<int> statisticalResult(vector<int>& arrayA) {
        int n = arrayA.size();
        vector<int> ans(n);
        vector<int> pre_mul(n, 1); // 前缀积表示除了当前元素所有前面元素的乘积
        vector<int> suf_mul(n, 1); // 后缀积 表示除了当前元素所有后面元素的乘积
        if (n == 0)
            return ans;
        pre_mul[0] = 1;
        suf_mul[n - 1] = 1;

        for (int i = 1; i < n; i++)
            pre_mul[i] = pre_mul[i - 1] * arrayA[i - 1];
        for (int i = n - 2; i >= 0; i--)
            suf_mul[i] = suf_mul[i + 1] * arrayA[i + 1];

        for (int i = 0; i < n; i++)
            ans[i] = pre_mul[i] * suf_mul[i];

        return ans;
    }
};

class Solution {
public:
    // 题主解法 nb 惨了
    // 时间 O(N)
    // 空间 O(1)
    vector<int> statisticalResult(vector<int>& arrayA) {
        int len = arrayA.size();
        if (len == 0)
            return {};
        vector<int> arrayB(len, 1);
        arrayB[0] = 1;
        int tmp = 1;
        for (int i = 1; i < len; i++) {
            // 将下面的三角部分累乘到答案数组中
            arrayB[i] = arrayB[i - 1] * arrayA[i - 1];
        }
        for (int i = len - 2; i >= 0; i--) {
            tmp *= arrayA[i + 1];
            arrayB[i] *= tmp; // 利用tmp将上面的三角部分累乘到答案中
        }
        return arrayB;
    }
};

// link :
// https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p

// 题解
// ![](https://pic.leetcode-cn.com/1599920669-zaVZDZ-Picture7.png)
// ![](https://pic.leetcode-cn.com/1599920669-atltNE-Picture4.png)