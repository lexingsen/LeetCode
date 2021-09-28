#include <vector>
#include <climits>
using namespace std;

/*
f:表示以i结尾子数组乘积为正数的最大长度
g:表示以i结尾子数组乘积为负数的最大长度
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int f = nums[0] > 0 ? 1 : 0;
        int g = nums[0] < 0 ? 1 : 0;
        int res = f;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                f = 0;
                g = 0;
            } else if (nums[i] > 0) {
                f++;
                g = g > 0 ? g + 1 : 0;
            } else if (nums[i] < 0) {
                int nf = g > 0 ? g + 1 : 0;
                int ng = f + 1;
                f = nf;
                g = ng;
            }
            res = max(res, f);
        }
        return res;
    }
};