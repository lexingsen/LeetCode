#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (!nums.size()) {
            return {};
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int s = nums[l] + nums[r];
            if (s == target) {
                return {l + 1, r + 1};
            } else if (s < target) {
                l++;
            } else if (s > target) {
                r--;
            }
        }
        return {};
    }
};