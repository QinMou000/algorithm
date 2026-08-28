#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 137. 只出现一次的数字 II 通用题解
int singleNumberⅡ(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int cnt = 0;
        int mask = 1 << i;
        for (int j = 0; j < n; j++) {
            if (mask & nums[j])
                cnt++;
        }
        ans |= (cnt % 3) << i;
    }
    return ans;
}

// 260. 只出现一次的数字 III
vector<int> singleNumberⅢ(vector<int> &nums) {
    int div = 0;
    int helper = 0;
    for (auto e: nums) {
        helper ^= e;
    }
    for (int i = 0; i < 32; i++) {
        if (helper & (1 << i)) {
            div = i;
            break;
        }
    }
    int ret1 = 0, ret2 = 0;
    for (auto e: nums) {
        if (e & (1 << div)) {
            ret1 ^= e;
        } else {
            ret2 ^= e;
        }
    }
    return {ret1, ret2};
}

// 1143. 最长公共子序列
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

struct Stripe {
    string message;
};

struct Block {
    vector<Stripe> Stripes;
};


std::string read(vector<Block> block, int n) {
    string ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            ans += block[j].Stripes[i].message;
        }
    }
    return ans;
}


int main() {
    vector<Block> ptr(4);
    ptr[0].Stripes.emplace_back("a");
    ptr[0].Stripes.emplace_back("b");
    ptr[0].Stripes.emplace_back("c");

    ptr[1].Stripes.emplace_back("d");
    ptr[1].Stripes.emplace_back("e");
    ptr[1].Stripes.emplace_back("f");

    ptr[2].Stripes.emplace_back("g");
    ptr[2].Stripes.emplace_back("h");
    ptr[2].Stripes.emplace_back("i");

    ptr[3].Stripes.emplace_back("j");
    ptr[3].Stripes.emplace_back("k");
    ptr[3].Stripes.emplace_back("l");

    cout << read(ptr, 4) << endl;;
    return 0;
}
