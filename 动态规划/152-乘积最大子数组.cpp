#include <vector>
#include <climits>
using namespace std;

/*
状态表示：
f[i] 以i为右端点子数组乘积的最大值
g[i] 以i为右端点子数组乘积的最小值

状态计算：
nums[i] > 0  f[i] = f[i - 1] * nums[i]  g[i] = g[i - 1] * nums[i]
nums[i] == 0 f[i] = f[i - 1]            g[i] = g[i-1]
nums[i] < 0  f[i] = g[i - 1] * nums[i]  g[i] = f[i - 1] * nums[i]
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f = nums[0];
        int g = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = nums[i], fa = f * a, ga = g * a;
            f = max(a, max(fa, ga));
            g = min(a, min(fa, ga));

            res = max(res, f);
        }
        return res;
    }
};



/*
暴力：
枚举所有的起终点，计算出乘积的最大值
时间复杂度O(n^3)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n;j ++) {
                int multi = 1;
                for (int k = i; k <= j; ++k) {
                    multi *= nums[k];
                }
                res = max(res, multi);
            }
        }
        return res;
    }
};