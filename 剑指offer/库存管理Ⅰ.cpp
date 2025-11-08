class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        int n = stock.size();
        int x = stock[n - 1], left = 0, right = n - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (stock[mid] < stock[right])
                right = mid;
            else if (stock[mid] > stock[right])
                left = mid + 1;
            else
                right--;
        }
        return stock[left];
    }
};

// TODO link : https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/description/?envType=problem-list-v2&envId=XApvNy3p&