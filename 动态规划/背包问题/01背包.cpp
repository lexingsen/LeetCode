#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
const int M = 100;
int n, m;
int v[N];
int w[N];
int f[N][M];

int zero_one_pack() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            if (j < v[i]) {
                f[i][j] = f[i - 1][j];
            } else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    return f[n][m];
}

int zero_one_pack_optimize_space() {
    vector<int> f(M+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; --j) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    return f[m];
}