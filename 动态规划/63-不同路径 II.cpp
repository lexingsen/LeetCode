#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (!grid.size()) {
            return 0;
        }
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    if (!i && !j) {
                        f[i][j] = 1;
                    } else {
                        if (i) {
                            f[i][j] += f[i - 1][j];
                        }
                        if (j) {
                            f[i][j] += f[i][j - 1];
                        }
                    }
                }
            }
        }
        return f[m - 1][n - 1];
    }
};