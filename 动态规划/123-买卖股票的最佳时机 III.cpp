#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

/*
至多交易两次

枚举两笔交易的分界点 (思想：前后缀分解)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 1);
        for (int i = 1, minp = INT_MAX; i <= n; i++) {
            // 第i天不买 f[i] = f[i - 1]  第i天卖 f[i] = prices[i] - minp
            f[i] = max(f[i - 1], prices[i - 1] - minp);
            minp = min(minp, prices[i - 1]);
        }

        int res = 0;
        // 枚举分界点 交易两次 第一次在[0,i-1] 最大利润为f[i-1]
        // [0,i-1] [i-1, n-1]
        // [0,i-1] 最大利润为 f[i-1]
        // [i-1,n-1] 最大利润为 res = max(res, maxp-prices[i-1])
        for (int i = n, maxp = 0; i >= 1; i--) {
            res = max(res, f[i - 1] + maxp - prices[i - 1]);
            maxp = max(maxp, prices[i - 1]);
        }

        return res;
    }
};