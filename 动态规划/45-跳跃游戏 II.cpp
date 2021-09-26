#include <vector>
#include <algorithm>
using namespace std;

// 本质上是图论问题，从起点到终点的最短路径  边的权值均为1
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            f[i] = INT_MAX;
        }

        // 松弛那些可以跳到的点
        for (int i = 0; i < n; ++i) {
            int cnt = nums[i];
            // j代表和i相连的点
            for (int j = i + 1; j <= min(n - 1, i + cnt); j++) {
                // 松弛从i到j的边能否使得从起点到终点的路径更短
                f[j] = min(f[j], f[i] + 1);
            }
        }
        return f[n - 1];
    }
};