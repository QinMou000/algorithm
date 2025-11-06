#include <iostream>
// #include <algorithm>
using namespace std;

const int N = 1e3 + 5;

int n, V;

int dp[N][N] = {0}; // dp[i][j] 表示背包从 0 - i 物品中任意取 大小不超过 j 的最大价值
int weight[N];
int value[N];

int main() {
    cin >> n >> V;
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
    for (int j = weight[0]; j <= V; j++) // 初始化第一行
        dp[0][j] = value[0];
    for (int i = 1; i < n; i++) // 遍历物品
        for (int j = 0; j <= V; j++) { // 背包容量
            if ( j >= weight[i]) // 能够装下
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else // 装不下
                dp[i][j] = dp[i - 1][j]; // 不选第 i 个物品
        }
    cout << dp[n - 1][V] << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")