#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        st = vector<bool>(n);
        path = vector<int>(n);
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            if (u == nums.size()) {
                ans.emplace_back(path);
                return;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                if (i && nums[i - 1] == nums[i] && st[i - 1]) {
                    continue;
                }
                st[i] = true;
                path[u] = nums[i];
                dfs(nums, u + 1);
                st[i] = false;
            }
        }
    }
};