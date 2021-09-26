#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


/*
状态表示 (集合，属性)
f[i][1] 表示第i家偷，从1~i能偷到的最大价值
f[i][0] 表示第i家不偷，从1~i能偷到的最大价值

状态计算 (集合划分的过程)
f[i][1] = nums[i-1]
i >= 2 && f[i][1] += max(f[i-2][1], f[i-2][0])

f[i][0] = max(f[i-1][1], f[i-1][0])

res = max(f[i][0], f[i][1])
*/

const int N = 110;
int f[N][2];

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(f, 0, sizeof(f));
        int res = INT_MIN;
        for (int i = 1; i <= n; i++) {
            f[i][1] = nums[i-1];
            if (i >= 2) {
                f[i][1] += max(f[i - 2][1], f[i-2][0]);
            }
            f[i][0] = max(f[i-1][1], f[i-1][0]);
            res = max(res, max(f[i][0], f[i][1]));
        }
        return res;
    }
};




#if 0
/*
状态表示
f[i]表示偷[1~n]家的最大值

状态计算
相隔的两个不能一块偷了，只能偷一家的

现在考虑第i家
1.如果不偷，f[i] = f[i-1]
2.如果偷, f[i] = nums[i-1], 并且当前的i家是>=2的，这样就可以偷i-2家的，因为i-1家不能偷，此时最大价值是f[i] += f[i-2];

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            // 第i家偷
            f[i] = nums[i - 1];
            if (i >= 2) {
                f[i] += f[i - 2];
            }
            // 第i家不偷 f[i] = f[i - 1]
            f[i] = max(f[i], f[i - 1]);
        }
        return f[n];
    }
};
#endif