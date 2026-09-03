#include <iostream>
#include <bits/stdc++.h>
#include "json.hpp"

using namespace std;
// 670. 最大交换
// 倒序遍历 s，同时维护最大数的下标 maxIdx。它只在遇到更大的数字才更新，遇到相同数字不会更新，从而满足上面讨论的「最后一个」。
// 如果发现 s[i]<s[maxIdx]，满足交换要求，我们先把这两个下标保存在变量 p 和 q 中。注：p 在遍历前的初始值为 −1。
// 继续向左遍历，如果又遇到 s[i]<s[maxIdx]，就更新 p=i, q=maxIdx，因为 s[i] 越靠左越好，我们要交换的是从左到右第一个右边有比它大的数字。
// 遍历结束，如果无需交换，即 p=−1，那么直接返回 num。否则交换 s[p] 和 s[q]，然后把 s 转换成数字返回。

int maximumSwap(int num) {
    string tmp = to_string(num);
    int maxIndex = tmp.size() - 1;
    int p = 0, q = 0;
    for (int i = tmp.size() - 1; i >= 0; i--) {
        if (tmp[i] > tmp[maxIndex]) {
            maxIndex = i;
        } else if (tmp[i] < tmp[maxIndex]) {
            p = i;
            q = maxIndex;
        }
    }
    swap(tmp[p], tmp[q]);
    return stoi(tmp);
}

// 76. 最小覆盖子串
string minWindow(string s, string t) {
    unordered_map<char, int> cnt;
    int kinds = 0;
    for (auto c: t)
        if (cnt[c]++ == 0)
            kinds++;
    int pos = 0, str_len = INT_MAX;
    int count = 0;
    for (int l = 0, r = 0; r < s.size(); r++) {
        if (--cnt[s[r]] == 0)
            count++;
        while (count == kinds) {
            if (r - l + 1 < str_len) {
                pos = l;
                str_len = r - l + 1;
            }
            if (++cnt[s[l++]] > 0) {
                count--;
            }
        }
    }
    return str_len == INT_MAX ? "" : s.substr(pos, str_len);
}

// 525. 连续数组
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> hash; // 前缀和->下标
    int sum = 0;
    int ans = 0;
    hash[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i] == 0 ? -1 : 1;
        if (hash.count(sum)) {
            ans = max(ans, i - hash[sum]);
        } else {
            hash[sum] = i;
        }
    }
    return ans;
}


using json = nlohmann::json;

/**
 * @brief 递归合并两个json，返回新对象，不修改入参
 * @param a json1
 * @param b json2
 * @return merged json
 */
json json_merge(const json &a, const json &b) {
    // 两者都是 object 对象，递归合并字典
    if (a.is_object() && b.is_object()) {
        json res = a; // copy a
        for (auto &[k, v_b]: b.items()) {
            if (res.contains(k)) {
                res[k] = json_merge(res[k], v_b);
            } else {
                res[k] = v_b;
            }
        }
        return res;
    }

    // 两者都是 array：拼接 a + b
    if (a.is_array() && b.is_array()) {
        json arr = a;
        for (auto &elem: b) {
            arr.push_back(elem);
        }
        return arr;
    }

    // 两者都是 bool：逻辑或
    if (a.is_boolean() && b.is_boolean()) {
        return a.get<bool>() || b.get<bool>();
    }

    // 两者都是数字（整数 / 浮点数）：相加
    if (a.is_number() && b.is_number()) {
        // 只要任意一个是浮点数，结果用double
        if (a.is_number_float() || b.is_number_float()) {
            return a.get<double>() + b.get<double>();
        } else {
            return a.get<std::int64_t>() + b.get<std::int64_t>();
        }
    }

    // 两者都是字符串：拼接
    if (a.is_string() && b.is_string()) {
        return a.get<std::string>() + b.get<std::string>();
    }

    return b;
}


int main() {
    json j1 = R"(
    {
        "num": 10,
        "str": "hello",
        "flag": false,
        "arr": [1,2],
        "sub": {"a":1, "b":[10]},
        "none_val": null
    }
    )"_json;

    json j2 = R"(
    {
        "num": 5,
        "str": " world",
        "flag": true,
        "arr": [3,4],
        "sub": {"a":2, "c":99},
        "none_val": 666,
        "new_key":123
    }
    )"_json;

    json out = json_merge(j1, j2);
    std::cout << out.dump(4) << std::endl;

    return 0;
}
