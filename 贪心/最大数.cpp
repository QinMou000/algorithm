class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> VeStr;
        for (int e : nums)
            VeStr.emplace_back(to_string(e));
        auto Compare = [](const string& x, const string& y) {
            return x + y > y + x;
        }; // 自定义比较函数

        sort(VeStr.begin(), VeStr.end(), Compare);
        if (VeStr[0] == "0")
            return "0";
        string ans;
        for (string& s : VeStr)
            ans += s;
        return ans;
    }
private:
    // void QuickSort(vector<string>& arr, int left, int right) {
    //     if (left >= right)
    //         return;
    //     int povit = patition(arr, left, right);

    //     QuickSort(arr, left, povit - 1);
    //     QuickSort(arr, povit + 1, right);
    // }
    // int patition(vector<string>& arr, int left, int right) {
    //     string x = arr[left];
    //     int l = left, r = right;

    //     while (l < r) {
    //         // 搞清楚是那两个元素相比较
    //         while (l < r && arr[r] + x >= x + arr[r])
    //             r--;
    //         while (l < r && arr[l] + x <= x + arr[l])
    //             l++;
    //         swap(arr[l], arr[r]);
    //     }
    //     swap(arr[left], arr[l]);
    //     return l;
    // }
};

// link : https://leetcode.cn/problems/largest-number/description/?envType=problem-list-v2&envId=greedy