#include <vector>
using namespace std;

/*
倒着递推
空间复杂度O(1)
时间复杂度O(n^2)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& f) {
        for (int i = f.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; j++) {
                f[i][j] += min(f[i + 1][j], f[i + 1][j + 1]);
            }
        }

        return f[0][0];
    }
};

/*
2
3 4
6 5 7
4 1 8 3
*/