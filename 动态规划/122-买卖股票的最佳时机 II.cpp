#include <climits>
#include <vector>
using namespace std;
/*
多次买卖
不能交叉

脑筋急转弯
核心思想：只要第二天比一天贵 就第一天买入第二天卖出去
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