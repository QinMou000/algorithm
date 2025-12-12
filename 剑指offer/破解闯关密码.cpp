class Solution {
public:
    string crackPassword(vector<int>& password) {
        vector<string> tmp;
        for (auto& n : password)
            tmp.push_back(to_string(n));
        string ans;
        // sort(tmp.begin(), tmp.end(), com);
        QuickSort(tmp, 0, tmp.size() - 1);
        for (auto& str : tmp)
            ans += str;
        return ans;
    }

private:
    void QuickSort(vector<string> &arr, int left, int right) {
        if (left >= right)
            return;
        int povit = patition(arr, left, right);

        QuickSort(arr, left, povit - 1);
        QuickSort(arr, povit + 1, right);
    }
    int patition(vector<string> &arr, int left, int right) {
        string x = arr[left];
        int l = left, r = right;

        while (l < r) {
            // 搞清楚是那两个元素相比较
            while (l < r && arr[r] + x >= x + arr[r])
                r--;
            while (l < r && arr[l] + x <= x + arr[l])
                l++;
            swap(arr[l], arr[r]);
        }
        swap(arr[left], arr[l]);
        return l;
    }

    static bool com(const string& x, const string& y) { return x + y < y + x; };
};

// 题解 :
// https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solutions/190476/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/?envType=problem-list-v2&envId=XApvNy3p

// link :
// https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p