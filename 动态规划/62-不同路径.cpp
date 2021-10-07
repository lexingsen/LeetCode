#include <vector>
using namespace std;

class Solution {
public:
    using ll = long long;
    vector<vector<ll>> f;
    int uniquePaths(int m, int n) {
        f = vector<vector<ll>>(110, vector<ll>(110, 0));
        for (int i = 0; i < m; i++) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }

        return f[m - 1][n - 1];
    }
};