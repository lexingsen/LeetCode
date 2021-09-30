#include <vector>
using namespace std;

class Solution {
public:

    using vi = vector<int>;
    using vb = vector<bool>;
    using vvi = vector<vector<int>>;

    vi path;
    vb st;
    vvi ans;
    void dfs(vi& nums, int u) {
        if (nums.size() == u) {
            ans.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st[i]) {
                continue;
            }
            st[i] = true;
            path[u] = nums[i];
            dfs(nums, u + 1);
            st[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        path = vi(n);
        st = vb(n);
        dfs(nums, 0);
        return ans;
    }
};