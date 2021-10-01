#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int n, int k, int u) {
        if (!n) {
            if (!k) {
                ans.emplace_back(path);
                return;
            }

        } else if (k) {
            for (int i = u; i <= 9; i++) {
                if (n >= i) {
                    path.emplace_back(i);
                    dfs(n - i, k - 1, i + 1);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(n, k, 1);
        return ans;
    }
};