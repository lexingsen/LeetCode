#include <vector>
using namespace std;

/*
最少硬币数

背包问题  完全背包

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        // 完全背包，初始只有f[0]=0合法
        vector<int> f(m + 1, 1e8);
        f[0] = 0;
        for (auto v: coins) {
            for (int j = v; j <= m; j++) {
                f[j] = min(f[j], f[j - v] + 1);
            }
        }
        return f[m] == 1e8 ? -1 : f[m];
    }
};