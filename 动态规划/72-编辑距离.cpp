#include <vector>
#include <string>
using namespace std;

/*
word1->word2
删除、替换、插入
状态表示
集合：
属性：min

状态计算
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[0][i] = i;
        }
        for (int i = 1; i <= m; i++) {
            f[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] != word2[j - 1]) {
                    f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                } else {
                    f[i][j] = f[i - 1][j - 1];
                }
            }
        }
        return f[m][n];
    }
};