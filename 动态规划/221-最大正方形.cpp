#include <vector>
#include <climits>
using namespace std;

/*
f[i][j] 表示以i,j为右下角的最大正方形的边长

证明比较难
f[i][j] <= min(f[i - 1][j] + 1, min(f[i - 1][j - 1] + 1, f[i][j - 1] + 1)) 
f[i][j] >= min(f[i - 1][j] + 1, min(f[i - 1][j - 1] + 1, f[i][j - 1] + 1)) 反证法
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int size = INT_MIN;
        vector<vector<int>> f(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i || !j) {
                    f[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') { // i >= 1 || j >= 1
                    f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                } else if (matrix[i][j] == '0') {
                    f[i][j] = 0;
                }
                size = max(size, f[i][j]);
            }
        }
        return size * size;
    }
};