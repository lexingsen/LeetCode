#include <vector>
using namespace std;

// 深搜
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;


    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.emplace_back(path);
            return;
        }
        int k = u + 1;
        for (int i = 0; i < k - u + 1; i++) {
            dfs(nums, k);
            path.emplace_back(nums[u]);
        }
        for (int i = 0; i < k - u + 1; i++) {
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};


// 迭代
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        for (int i = 0; i < 1 << n; i++) {
            vector<int> path;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    path.emplace_back(nums[j]);
                }
            }
            ans.emplace_back(path);
        }


        return ans;
    }
};