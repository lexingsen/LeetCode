#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        // 枚举的是在第i天出售股票
        for (int i = 0, minp = INT_MAX; i < prices.size(); i++) {
            res = max(res, prices[i] - minp);
            minp = min(minp, prices[i]);
        }

        return res;
    }
};