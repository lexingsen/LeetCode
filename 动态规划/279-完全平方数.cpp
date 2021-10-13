#include <vector>
using namespace std;

class Solution {
public:
    // 完全背包
    int numSquares(int n) {
        vector<int> f(n + 1, 1e8);
        f[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                f[j] = min(f[j - i * i] + 1, f[j]);
            }
        }
        return f[n];
    }
};