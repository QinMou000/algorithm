class Solution {
public:
    // 哈希解法不写了

    int BinarySearch(vector<int>& price, int tar) {
        // 二分
        // 时间 O(nlogn)
        // 空间 O(1)
        int n = price.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (price[mid] > tar)
                right = mid - 1;
            else if (price[mid] < tar)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& price, int target) {
        for (auto& e : price) {
            int x = target - e;
            int index = BinarySearch(price, x);
            if (index != -1)
                return {e, price[index]};
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        // 双指针
        // 时间 O(n)
        // 空间 O(1)
        int n = price.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            // 判断条件最好不要用相加后的结果
            // 应该用target - price[left] 跟 price[right]比较 保证不会溢出
            int cur = price[left] + price[right];
            if (cur > target)
                right--;
            else if (cur < target)
                left++;
            else
                return {price[left], price[right]};
        }
        return {};
    }
};

// link : https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p