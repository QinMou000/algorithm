#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    // 64. 最小路径和
    int minPathSum(std::vector<std::vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        // 走到当前格子的最小权值
        std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 2; i <= m; i++) {
            dp[i][0] = INT_MAX;
        }
        for (int j = 2; j <= n; j++) {
            dp[0][j] = INT_MAX;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }

    // 16. 最接近的三数之和
    int threeSumClosest(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int div = INT_MAX; // 当前最小差值
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < n && r > i && l < r) {
                int helper = nums[l] + nums[r] + nums[i];
                if (abs(helper - target) < div) {
                    ans = helper;
                    div = abs(helper - target);
                }
                if (helper - target > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }

    // 72. 编辑距离
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size(), n = word2.size();
        // word1的前i个字符变化到word2的前j个字符需要的最小操作数
        std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
        // 需要多定义一行一列 用来表示空串
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] =
                        std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

// 155. 最小栈 不用辅助栈
class MinStack {
private:
    std::stack<long long> stk;
    long long minval;

public:
    MinStack() {
    }

    void push(int value) {
        if (stk.empty()) {
            stk.push(0);
            minval = value;
        } else {
            long long diff = value - minval;
            stk.push(diff);
            if (diff < 0) {
                minval = value; // 当前push的value是新的最小值
            }
        }
    }

    void pop() {
        long long diff = stk.top();
        stk.pop();
        if (diff < 0) {
            // 插入的时候value就是最小值
            // 我们需要更新minval
            minval = minval - diff;
        }
    }

    int top() {
        long long diff = stk.top();
        return diff < 0 ? minval : minval + diff;
    }

    int getMin() { return minval; }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
