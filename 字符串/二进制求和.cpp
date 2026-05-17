class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0, j = 0;
        string ans;
        int cur = 0;
        while (i < a.size() || j < b.size()) {
            int x1, x2;
            if (i >= a.size())
                x1 = 0;
            else
                x1 = a[i] - '0';
            if (j >= b.size())
                x2 = 0;
            else
                x2 = b[j] - '0';
            // cout << x1 << " " << x2 << endl;
            cur += (x1 + x2);
            ans += to_string(cur % 2);
            cout << cur << endl;
            cur /= 2;
            cout << cur << endl;
            i++, j++;
            cout << endl;
        }
        while (cur) {
            ans += to_string(cur % 2);
            cur /= 2;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// link : https://leetcode.cn/problems/JFETK5/description/