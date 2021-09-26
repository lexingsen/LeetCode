#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // j 表示i + nums[i]可以跳过去的下标
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (j < i) {
                return false;
            }
            j = max(j, i + nums[i]);
        }
        return true;
    }
};