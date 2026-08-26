#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 215. 数组中的第K个最大元素
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mid;
        while (true) {
            mid = QuickSort(nums, l, r);
            if (mid == n - k)
                return nums[mid];
            else if (mid > n - k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    int QuickSort(vector<int> &nums, int l, int r) {
        // 避免数组本来有序造成的On^2退化
        int randomIndex = rand() % (r - l + 1) + l;
        swap(nums[randomIndex], nums[l]);

        int left = l, right = r;
        int privot = nums[l];
        while (left < right) {
            while (left < right && nums[right] >= privot) {
                right--;
            }
            while (left < right && nums[left] <= privot) {
                left++;
            }
            swap(nums[left], nums[right]);
        }
        swap(nums[l], nums[left]);
        return left;
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

    // 102. 二叉树的层序遍历
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int> > ans;
        if (!root)
            return ans;
        q.push(root);
        while (!q.empty()) {
            vector<int> ret;
            int size = q.size();
            while (size--) {
                TreeNode *node = q.front();
                ret.push_back(node->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.emplace_back(ret);
            ret.clear();
        }
        return ans;
    }

    //"cbabd"
    // 01234
    // 5. 最长回文子串
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r <= n - 1) {
                if (s[l] != s[r])
                    break;
                l--, r++;
            }
            if (r - l - 1 > maxLen) {
                maxLen = r - l - 1;
                ans = s.substr(l + 1, maxLen);
            }
            l = i, r = i + 1;
            while (l >= 0 && r <= n - 1) {
                if (s[l] != s[r])
                    break;
                l--, r++;
            }
            if (r - l - 1 > maxLen) {
                maxLen = r - l - 1;
                ans = s.substr(l + 1, maxLen);
            }
        }
        return ans;
    }

    // 15. 三数之和
    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if (cur == 0) {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                } else if (cur > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
