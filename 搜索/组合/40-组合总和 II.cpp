#include <vector>
#include <algorithm>
using namespace std;


/*
每个数字可以选择多次
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& c, int target, int u) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        }
        if (u == c.size()) {
            return;
        }
        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) {
            k++;
        }
        int cnt = k - u;
        for (int i = 0; c[u] * i <= target && i <= cnt; i++) {
            dfs(c, target - c[u] * i, k);
            path.emplace_back(c[u]);
        }
        for (int i = 0; c[u] * i <= target && i <= cnt; i++) {
            path.pop_back();   
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, target, 0);
        return ans;
    }
};