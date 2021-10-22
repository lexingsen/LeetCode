#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;

    bool check(int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }
        return true;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            ans += dfs(grid, x + dx[i], y + dy[i], n, m);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j, n, m));
                }
            }
        }

        return res;
    }
};