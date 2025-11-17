class Solution {
public:
    // 注意边界情况 left 和 right 都是左闭右闭的
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        vector<int> tmp(right - left + 1); // 创建临时数组
        int l = left, r = mid + 1;
        int i = 0;
        while (l <= mid && r <= right) {
            if (arr[l] > arr[r])
                tmp[i++] = arr[r++];
            else
                tmp[i++] = arr[l++];
        }
        while (r <= right)
            tmp[i++] = arr[r++];
        while (l <= mid)
            tmp[i++] = arr[l++];

        for (int j = left; j <= right; j++)
            arr[j] = tmp[j - left]; // 拷贝到源数组
    }

    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        int n = stock.size();
        mergeSort(stock, 0, n - 1); // 左闭右闭区间
        return {stock.begin(), stock.begin() + cnt};
    }
};
// ps : 下次记得用快排 !!!
// link : https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p