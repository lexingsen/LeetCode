#include <vector>
using namespace std;

class Solution {
public:
    
    int n;
    vector<vector<string>> ans;
    vector<string> path;
    vector<bool> dg;
    vector<bool> udg;
    vector<bool> col;
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);
        path = vector<string>(n,  string(n, '.'));
        dfs(0);
        return ans;
    }

    void dfs(int x) {
        if (x == n) {
            ans.emplace_back(path);
            return;
        }

        for (int y = 0; y < n; y++) {
            if (!col[y] && !dg[x - y + n] && !udg[y + x]) {
                col[y] = dg[x - y + n] = udg[y + x] = true;
                path[x][y] = 'Q';
                dfs(x + 1);
                path[x][y] = '.';
                col[y] = dg[x - y + n] = udg[y + x] = false;
            }
        }
    }
};