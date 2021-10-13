#include <vector>
using namespace std;

/*
完全背包求方案数
*/
class Solution {
public:
    int change(int m, vector<int>& coins) {
        vector<int> f(m + 1);
        f[0] = 1;
        for (auto v: coins) {
            for (int i = v; i <= m; i++) {
                f[i] += f[i - v];
            }
        }
        return f[m];
    }
};