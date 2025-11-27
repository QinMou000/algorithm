class Solution {
public:
    string reverseMessage(string message) {
        int n = message.size(), i = 0;
        vector<string> tmp;

        while (i < n) {
            while (i < n && message[i] == ' ')
                i++; // 跳过前面所有空格
            if (i >= n)
                break; // 这里不要直接返回空串
            int j = i;
            while (j < n && message[j] != ' ')
                j++; // 截取字符串
            tmp.emplace_back(message.substr(i, j - i));
            i = j; // 更新i
        }
        if (tmp.empty()) // 直接在这里判断 tmp 是否为空就好
            return "";

        for (auto& s : tmp)
            cout << s << endl;
        std::ostringstream oss;
        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            oss << *it;
            if (it != tmp.rend() - 1)
                oss << " "; // 不是最后一个单词就添加空格
            it++;
        }
        return oss.str();
    }
};

// class Solution {
// public:
//     // 大佬代码
//     string reverseMessage(string s) {
//         stack<string> stk;
//         string res, str;
//         istringstream ss(s);
//         while (ss >> str)
//             stk.push(str), stk.push(" ");
//         if (!stk.empty())
//             stk.pop();
//         while (!stk.empty())
//             res += stk.top(), stk.pop();
//         return res;
//     }
// };

// link : https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/description/?envType=problem-list-v2&envId=XApvNy3p