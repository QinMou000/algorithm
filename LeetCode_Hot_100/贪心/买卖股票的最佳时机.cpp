class Solution {
public:
    const static int N = 1e5 + 10;
    int maxProfit(vector<int>& prices) {
        // 定一个位置 看前面的最小值
        int dp[N] = {0}; // 表示该位置 前面的最小值 (包含该位置)
        dp[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (dp[i - 1] > prices[i])
                dp[i] = prices[i];
            else
                dp[i] = dp[i - 1];
        }
        // for (int i = 0; i < prices.size(); i++) {
        //     cout << dp[i] << endl;
        // }
        int ans = 0;
        for (int i = prices.size() - 1; i > 0; i--) {
            if (prices[i] - dp[i - 1] > ans)
                ans = prices[i] - dp[i - 1];
        }
        return ans;
    }
};

// link : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/136684/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。