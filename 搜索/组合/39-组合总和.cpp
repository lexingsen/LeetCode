#include <vector>
using namespace std;


/*
不包含重复元素，每个数字可以选择多次(无限次)
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
        for (int i = 0; i * c[u] <= target; i++) {
            dfs(c, target - i * c[u], u + 1);
            path.emplace_back(c[u]);
        }

        for (int i = 0; i * c[u] <= target; i++) {
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(c, target, 0);
        return ans;
    }
};