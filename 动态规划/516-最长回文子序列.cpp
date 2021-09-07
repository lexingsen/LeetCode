#include <string>
#include <vector>
using namespace std;

/*
f[i][j]: 表示s[i...j]会问子序列长度的最大值
长度为1时: f[i][i]=1
长度为2时: s[i]=s[i+1], f[i][i+1]=2
长度为[3, n]时:
    枚举长度  L=j-i+1
    左边界 i
    右边界 j=L+i-1
    (1) s[i]==s[j]   f[i][j] = f[i+1][j-1]+2
    (2) s[i]!=s[j]   f[i][j] = max(f[i+1][j], f[i][j-1]) 即包含s[i]或s[j]其中一个字符的回文子序列的最大长度
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            f[i][i] = 1;
        }

        for (int i = 0; i+1 < n; i++) {
            if (s[i] == s[i+1]) {
                f[i][i+1] = 2;
            } else {
                f[i][i+1] = 1;
            }
        }

        for (int L = 3; L <= n; L++) {
            for (int i = 0; L+i-1 < n; i++) {
                int j = L+i-1;
                if (s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1] + 2;
                } else {
                    f[i][j] = max(f[i+1][j], f[i][j-1]);
                }
            }
        }
        return f[0][n-1];
    }
};