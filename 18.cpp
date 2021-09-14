#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end()); // 排序，保证了单调性
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    int x = nums[i] + nums[j];
                    int y = nums[l] + nums[r];
                    // int x = (nums[i] + nums[j] + nums[l] + nums[r]); // 整数可能会溢出
                    if (x == target - y) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r-1]) {
                            r--;
                        }
                        l++;
                        r--;
                    }
                    if (x < target - y) {
                        l++;
                    }
                    if (x > target - y) {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};