#include <vector>
#include <queue>
using namespace std;

#define x first
#define y second

class Solution {
public:
    using pii = pair<int, int>;
    
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0; // 好橘子的数量
        int ans = 0;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0; 
                } else if (grid[i][j] == 1) {
                    cnt += 1;
                }
            }
        }

        while (q.size()) {
            auto t = q.front();
            q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int x = t.x + dx[i];
                int y = t.y + dy[i];
                // 1.下标不在范围内
                // 2.grid[x][y] == 0 当前位置没有橘子
                // 3.dist[x][y] == -1 
                if (x < 0 || x >= n || y < 0 || y >= m || ~dist[x][y] || !grid[x][y]) {
                    continue;
                }
                q.push({x, y});
                dist[x][y] = dist[t.x][t.y] + 1;
                if (grid[x][y] == 1) {
                    cnt -= 1;
                    ans = dist[x][y];
                    if (!cnt) {
                        break;
                    }
                }
            }

        }
        
        return cnt ? -1 : ans;
    }
};