#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return;
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
        }
        while (j < n) {
            nums[j++] = 0;
        }
    }
};