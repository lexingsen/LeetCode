#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        if (!mat.size() || !mat[0].size()) {
            return;
        }
        int m = mat.size();
        int n = mat[0].size();
        bool row0 = false;
        bool col0 = false;
        for (int i = 0; i < n; i++) {
            if (!mat[0][i]) {
                row0 = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (!mat[i][0]) {
                col0 = true;
            }
        }

        // 枚举列
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    mat[0][j] = 0;
                }
            }

        }

        // 枚举行
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (!mat[i][j]) {
                    mat[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (!mat[i][0]) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (!mat[0][j]) {
                for (int i = 1; i < m; i++) {
                    mat[i][j] = 0;
                }
            }
        }

        if (row0) {
            for (int i = 0; i < n; i++) {
                mat[0][i] = 0;
            }
        }

        if (col0) {
            for (int i = 0; i < m; i++) {
                mat[i][0] = 0;
            }
        }
    }
};