#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 912. 排序数组
// 归并排序
void MergeSort(vector<int> &nums, int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    MergeSort(nums, l, mid);
    MergeSort(nums, mid + 1, r);
    vector<int> tmp;

    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (nums[i] > nums[j])
            tmp.push_back(nums[j++]);
        else
            tmp.push_back(nums[i++]);
    }
    while (i <= mid)
        tmp.push_back(nums[i++]);
    while (j <= r)
        tmp.push_back(nums[j++]);
    for (int k = l; k <= r; k++)
        nums[k] = tmp[k - l];
}

vector<int> sortArray(vector<int> &nums) {
    MergeSort(nums, 0, nums.size() - 1);
    return nums;
}

// 78. 子集
vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int> > ans;

    function<void(vector<int> &output, int pos)> dfs =
            [&](vector<int> &output, int pos) {
        if (pos > nums.size() - 1) {
            ans.emplace_back(output);
            return;
        }
        // 不选
        dfs(output, pos + 1);
        // 选
        output.push_back(nums[pos]);
        dfs(output, pos + 1);
        output.pop_back();
    };
    vector<int> output = {};
    dfs(output, 0);
    return ans;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {
    }
};

// LCR 143. 子结构判断
bool dfs(TreeNode *A, TreeNode *B) {
    if (!B)
        return true;
    if (!A)
        return false;
    if (A->val != B->val)
        return false;
    return dfs(A->left, B->left) && dfs(A->right, B->right);
}

bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (!B)
        return false;
    if (!A)
        return false;
    return dfs(A, B) || isSubStructure(A->left, B) ||
           isSubStructure(A->right, B);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
