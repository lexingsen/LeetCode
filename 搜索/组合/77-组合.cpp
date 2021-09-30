#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int n, int k, int st) {
        if (!k) {
            ans.emplace_back(path);
            return;
        }
        for (int i = st; i <= n; i++) {
            path.emplace_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};