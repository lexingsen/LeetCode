#include <climits>
#include <vector>
using namespace std;
/*
多次买卖
不能交叉
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i + 1 < prices.size(); i++) {
            res += max(0, prices[i + 1] - prices[i]);
        }
        return res;
    }
};