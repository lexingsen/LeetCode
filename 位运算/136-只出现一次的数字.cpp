#include <vector>
using namespace std;

class Solution {
public:

    // 0 ^ n = n
    // n ^ n = 0
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};