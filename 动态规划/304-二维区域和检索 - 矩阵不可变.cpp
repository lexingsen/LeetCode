#include <vector>
using namespace std;

class NumMatrix {
public:
    // 二维前缀和
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        s = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        return s[x2 + 1][y2 + 1] - s[x2 + 1][y1 - 1 + 1] - s[x1 - 1 + 1][y2 + 1] + s[x1 - 1 + 1][y1 - 1 + 1];
    }
private:
    vector<vector<int>> s;
};