#include <vector>
#include <climits>
using namespace std;

/*
f[i] 必选i
g[i] 必不选i
不选1 max(f[n], g[n])
选1 g[n]
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> f(n + 1);
        vector<int> g(n + 1);
        int res = INT_MIN;
        // 不选1 n可选可不选
        for (int i = 2; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        res = max(res, max(f[n], g[n]));
        f[1] = nums[0]; // 必选1 必不选n
        g[1] = INT_MIN;
        for (int i = 2; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        res = max(res, g[n]);
        return res;
    }
};