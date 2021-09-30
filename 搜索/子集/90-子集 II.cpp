#include <vector>
using namespace std;

// 深搜
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.emplace_back(path);
            return;
        }
        int k = u + 1;
        while (k < nums.size() && nums[k] == nums[u]) {
            k++;
        }
        for (int i = 0; i < k - u + 1; i++) {
            dfs(nums, k);
            path.emplace_back(nums[u]);
        }

        for (int i = 0; i < k - u + 1; i++) {
            path.pop_back();   
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};













