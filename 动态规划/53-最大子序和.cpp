#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int now = max(last, 0) + nums[i];
            res = max(res, now);
            last = now;
        }
        return res;
    }
};