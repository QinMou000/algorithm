class Solution
{
public:
    int mergeSort(vector<int> &record, int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int ans = 0; // 分别加上左右两边的逆序对
        ans += mergeSort(record, left, mid);
        cout << ans << endl;

        ans += mergeSort(record, mid + 1, right);
        cout << ans << endl;

        int l = left, r = mid + 1, index = 0; // index是专门给辅助数组用的
        vector<int> tmp(right - left + 1);
        while (l <= mid && r <= right)
        {
            if (record[l] > record[r])
            {
                // 左边部分数组的最左边(最小的)大于右边的最左边(也是最小的)
                // 那么左边的所有数都大于record[r] 所以存在 mid - l + 1 个逆序对
                ans += mid - l + 1;
                tmp[index++] = record[r++];
            }
            else
                tmp[index++] = record[l++];
        }
        while (l <= mid)
            tmp[index++] = record[l++];
        while (r <= right)
            tmp[index++] = record[r++];

        // 写回原数组
        for (int i = left; i <= right; i++)
            record[i] = tmp[i - left];
        cout << ans << endl;

        return ans;
    }

    int reversePairs(vector<int> &record)
    {
        int n = record.size();
        return mergeSort(record, 0, n - 1);
    }
};

// 关于这个用归并的解法为什么不会在每一层归并的时候有重复
// 因为每一次归并都是在自己那一边进行归并 计算的逆序对也只是自己的那一边的逆序对
// 也就是说是先单独计算两边的逆序对个数 在将数组合并算整个数组的逆序对个数
// 如果还是想不清楚 可以用下面的例子自己模拟一下归并的过程
// [9, 7, 5, 4, 6]

// link : https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/?envType=problem-list-v2&envId=XApvNy3p