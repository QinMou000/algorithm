class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_set<int> set;
        for (int i = 0; i < arr1.size(); ++i) {
            int num = arr1[i];
            while (num) {
                set.insert(num);
                num /= 10;
            }
        }
        for (int i = 0; i < arr2.size(); ++i) {
            int num = arr2[i];
            while (num) {
                if (set.count(num) && num > ans)
                    ans = num;
                num /= 10;
            }
        }
        return ans == 0 ? 0 : to_string(ans).size();
    }
};

// 一个整数的前缀可以通过不断去掉末位数字得到，对应的操作是不断对 10 做整数除法。例如整数 1234 的所有前缀为 1234,123,12,1。
// 我们先遍历 arr1,对其中每个元素不断除以 10,将得到的所有前缀存入哈希表 set
// 随后遍历 arr2,对其中每个元素同样不断除以 10 枚举前缀。若当前前缀在 set 中出现过，说明 arr1和 arr2中存在一对数拥有该公共前缀,用它更新最大公共前缀值 ans
// 最终 ans 的十进制位数即为答案。若 ans 为 0,说明不存在公共前缀,返回 0

// link : https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/description/