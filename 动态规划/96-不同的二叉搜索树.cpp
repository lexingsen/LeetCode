const int N = 42;
long long memo[N][N];
class Solution {
public:

    long long C(int n, int m) {
        if (n == m || m == 0) {
            return 1;
        }
        if (memo[n][m]) {
            return memo[n][m];
        }

        return memo[n][m] = C(n - 1, m) + C(n - 1, m - 1);
    }

    int numTrees(int n) {
        return C(2 * n, n) / (n + 1);
    }
};