#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubstring(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j) {
                    f[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else if (text1[i - 1] != text2[j - 1]) {
                    f[i][j] = 0;
                }
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};


int main() {
    string s1 = "ACGTA";
    string s2 = "AACGTTAG";
    Solution sol;
    cout << sol.longestCommonSubstring(s1, s2);
    return 0;
}