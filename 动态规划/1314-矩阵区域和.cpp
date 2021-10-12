#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> s = vector<vector<int>>(m + 1, vector<int>(n + 1));
        vector<vector<int>> ans = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int x1 = max(1, i - k);
                int y1 = max(1, j - k);
                int x2 = min(m, i + k);
                int y2 = min(n, j + k);
                ans[i][j] = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];  
            }
        }
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = ans[i + 1][j + 1];
            }
        }
        return res;
    }
};