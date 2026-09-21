// 33. 搜索旋转排序数组

int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[l] <= nums[mid]) {
            // 左边有序
            if (target >= nums[l] && target <= nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else {
            // 右边有序
            if (target >= nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

// 9. 组合总和
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    function<void(vector<int> &, int, int)> dfs = [&](vector<int> &out, int sum, int pos) {
        if (sum == target) {
            ans.emplace_back(out);
            return;
        }
        if (pos == candidates.size() || sum > target)
            return;

        // 选
        out.push_back(candidates[pos]);
        dfs(out, sum + candidates[pos], pos);
        out.pop_back();
        // 不选
        dfs(out, sum, pos + 1);
    };
    vector<int> out;
    dfs(out, 0, 0);
    return ans;
}

// 912. 排序数组
int QuickSortHelper(vector<int> &nums, int l, int r) {
    int R = l + rand() % (r - l + 1);
    swap(nums[R], nums[l]);

    int left = l, right = r;
    while (left < right) {
        // 都要找严格大于或者严格小于的元素
        while (left < right && nums[l] <= nums[right])
            right--;
        while (left < right && nums[l] >= nums[left])
            left++;
        swap(nums[left], nums[right]);
    }
    // 出循环时 left == right
    // 可以保证 left 位置的值比 l 位置的值小
    swap(nums[l], nums[left]);
    return left;
}
void QuickSort(vector<int> &nums, int l, int r) {
    if (l >= r)
        return;

    int povit = QuickSortHelper(nums, l, r);

    QuickSort(nums, l, povit - 1);
    QuickSort(nums, povit + 1, r);
}

vector<int> sortArray(vector<int> &nums) {
    QuickSort(nums, 0, nums.size() - 1);
    return nums;
}