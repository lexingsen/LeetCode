#include <vector>
#include <climits>
using namespace std;

/*
一次买卖
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        // 枚举的是在第i天出售股票   
        // minp表示[1, i-1]中股票最便宜的那一天的价格  minp = min{prices[0],prices[1],prices[2],...,prices[i-1]}
        for (int i = 0, minp = INT_MAX; i < prices.size(); i++) {
            res = max(res, prices[i] - minp);
            minp = min(minp, prices[i]); // 买入时的最小值
        }

        return res;
    }
};