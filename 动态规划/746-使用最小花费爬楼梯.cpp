#include <vector>
using namespace std;

/*
f[i] 表示从0跳到第i层的最低花费
第i层可以从第i-1层和第i-2层跳过来，如果希望当前层花费最低
那么就需要选择从第i-1层和第i-2层跳过来最小的那一个再加上
当前的点的点权，才会使得f[i]最小

f[i] = min(f[i - 1], f[i - 2]) + cost[i];


最后一次n
可以从f[n-1]和f[n-2]转移过来
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n);
        f[0] = cost[0];
        f[1] = cost[1];
        for (int i = 2; i < n; i++) {
            f[i] = min(f[i - 1], f[i - 2]) + cost[i];
        }
        return min(f[n - 1], f[n - 2]);
    }
};