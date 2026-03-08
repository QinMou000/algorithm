#include <iostream>
#include <vector>

using namespace std;

#define HEAP

#ifdef QUICK
int partition(vector<int> &nums, int left, int right) {
    int l = left, r = right;
    int x = nums[l]; // 基准值
    while (l < r) {
        while (l < r && nums[r] >= x)
            r--;
        while (l < r && nums[l] <= x)
            l++;
        swap(nums[l], nums[r]);
    }
    swap(nums[left], nums[l]);
    return l; // 返回中间值下标
}

void QuickSort(vector<int> &nums, int left, int right) {
    if (left >= right)
        return;
    int privot = partition(nums, left, right);

    QuickSort(nums, left, privot - 1);
    QuickSort(nums, privot + 1, right);
}

int main() {
    vector<int> arr = {2, 5, 8, 6, 4, 9, 3, 1, 7};
    QuickSort(arr, 0, arr.size() - 1);
    for (auto &e: arr)
        cout << e << " ";
    cout << endl;
    return 0;
}
#endif

#ifdef MERGE
void MergeSort(vector<int> &nums, int left, int right);

int main() {
    vector<int> arr = {2, 5, 8, 6, 4, 9, 3, 1, 7};
    MergeSort(arr, 0, arr.size() - 1);
    for (auto &e: arr)
        cout << e << " ";
    cout << endl;
    return 0;
}

void MergeSort(vector<int> &nums, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    // 现在可以理解为 left - mid与 mid + 1 - right 都是有序的
    int begin1 = left, begin2 = mid + 1;
    vector<int> tmp(right - left + 1);
    int i = 0; // 专门为tmp做下标的
    while (begin1 <= mid && begin2 <= right) {
        if (nums[begin1] > nums[begin2])
            tmp[i++] = nums[begin2++];
        else
            tmp[i++] = nums[begin1++];
    }
    while (begin1 <= mid)
        tmp[i++] = nums[begin1++];
    while (begin2 <= right)
        tmp[i++] = nums[begin2++];
    for (int j = 0; j < tmp.size(); j++) {
        nums[j + left] = tmp[j];
    }
}
#endif

#ifdef HEAP
void HeapSort(vector<int> &nums);

int main() {
    vector<int> arr = {2, 5, 8, 6, 4, 9, 3, 1, 7};
    HeapSort(arr);
    for (auto &e: arr)
        cout << e << " ";
    cout << endl;
    return 0;
}

// 向下调整
// 大顶堆
void AdjustDown(vector<int> &nums, int parent, int n) {
    int child = parent * 2 + 1; // 假设第一个孩子更大
    while (child < n) {
        // 如果第二个孩子存在 并且更大1
        if (child + 1 < n && nums[child + 1] > nums[child])
            child++;
        if (nums[child] > nums[parent]) {
            swap(nums[child], nums[parent]);
            parent = child;
            child = parent * 2 + 1;
        } else
            break;
    }
}

// 下标是从 0 开始计算
void HeapSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = (n - 1) / 2; i >= 0; i--)
        AdjustDown(nums, i, n); // 从最后一个非叶子节点开始建堆
    for (int i = n - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        AdjustDown(nums, 0, i);
    }
}
#endif
