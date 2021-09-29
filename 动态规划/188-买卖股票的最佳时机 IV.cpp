#include <vector>
using namespace std;

const int N = 1e2 + 10;
const int M = 1e3 + 10;
int f[M][N][M];

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int n = prices.size();
        for (int i = 0; i <= k; i++) {
            f[0][i][1] = -prices[0];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
            }
        }
        return f[n][k][0];
    }
};