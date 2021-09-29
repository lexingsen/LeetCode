#include <vector>
using namespace std;


/*
状态表示
f[i][0] 表示第i天没有持有股票的最大利润
f[i][1] 表示第i天持有股票的最大利润

f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i])
f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i])
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        f[0][0] = 0;
        f[0][1] = -prices[0];
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            if (i >= 2) {
                f[i][1] = max(f[i - 1][1], f[i - 2][0] - prices[i - 1]);
            } else {
                f[i][1] = max(f[i - 1][1], -prices[i - 1]);
            }
        }
        return f[n][0];
    }
};