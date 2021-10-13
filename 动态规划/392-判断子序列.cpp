#include <string>
#include <vector>
using namespace std;


/*
判断s是否为t的子序列
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        f[0][0] = true;
        // base case line
        // row  "" 是 t任意子串的子序列
        for (int i = 1; i <= n; i++) {
            f[0][i] = true;
        }
        // col
        for (int i = 1; i <= m; i++) {
            f[i][0] = false;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][j - 1] == true) {
                    f[i][j] = true;
                } else if (s[i - 1] == t[j - 1] && f[i - 1][j - 1] == true) {
                    f[i][j] = true;
                } else {
                    f[i][j] = false;
                }
            }
        }
        return f[m][n];
    }
};