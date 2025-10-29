class Solution
{
public:
    // // 向上调整
    // void AdjustUp(vector<int>& nums, int child) {
    //     // 计算i位置的父亲位置
    //     int parent = (child - 1) / 2;
    //     while (child > 0 && nums[parent] > nums[child]) // 小顶堆
    //     {
    //         swap(nums[parent], nums[child]);
    //         child = parent;
    //         parent = (child - 1) / 2;
    //     }
    // }
    // 向下调整
    void AdjustDown(vector<int> &nums, int parent, int n)
    {                               // 这个n就是 nums.size() 或者 heap.size() 的意思
        int child = parent * 2 + 1; // 假设左孩子是两个孩子中最小的
        while (child < n)
        {
            // 如果右孩子存在且比较小 child++ 索引到右孩子
            if (child + 1 < n && nums[child] > nums[child + 1])
                child++;
            if (nums[child] < nums[parent])
            { // 小顶堆
                swap(nums[child], nums[parent]);
                parent = child;
                child = parent * 2 + 1;
            }
            else // 否则两个孩子都满足堆的规则
                break;
        }
    }

    // 向下调整 递归实现
    void AdjustDown(vector<int> &nums, int parent, int n)
    {
        // 小根堆
        int child = parent * 2 + 1;
        if (child >= n)
            return;
        if (child + 1 < n && nums[child] > nums[child + 1]) // 右孩子存在且较小
            child++;                                        // 找到左右孩子中最小的那一个

        // 如果父亲大于了最小的孩子 就将较大的父亲换下去
        if (nums[parent] > nums[child])
        {
            swap(nums[child], nums[parent]);
            // 此时递归 child下标的位置就是换下去的父亲 继续下
            AdjustDown(nums, child, n);
        }
    }
    void HeapSort(vector<int> &nums)
    {
        int n = nums.size();
        // 从最后一个非叶子结点开始向下调整 建堆
        for (int i = (n - 1) / 2; i >= 0; i--)
            AdjustDown(nums, i, n); // 假设这个数组是一个实际有 n - 1 个元素的堆
        // 将堆中最后一个元素和堆顶元素交换后进行向下调整
        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[i], nums[0]); // 最后一个元素就不被算在堆里面了
            // 所以这个堆实际只有 i - 1 个元素
            AdjustDown(nums, 0, i);
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        HeapSort(nums);
        return nums[k - 1];
    }
};

// link :