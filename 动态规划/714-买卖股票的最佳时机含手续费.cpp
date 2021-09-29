#include <vector>
using namespace std;

/*
状态表示
f[i][0] 表示第i天没有持有股票的最大利润
f[i][1] 表示第i天持有股票的最大利润

手续费在一笔交易中买入和卖出只支付手续费一次

状态计算
f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i] - fee);
第i-1天就没有持有  第i-1天持有，i天卖出  获得利润prices[i]支付手续费fee

f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i] - fee)
第i-1天就持有 第i-1天未持有，i天买入 失去利润prices[i],支付手续费fee
*/


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        // base case
        // 第一天没有持有 最大利润为0
        // 第一天持有 最大利润为 -prices[0] - fee    0 - (买如当天股票的钱+以及当天交易的手续费)
        f[0][0] = 0;
        f[0][1] = -prices[0] - fee; 
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1] - fee);
        }
        return f[n][0];
    }
};