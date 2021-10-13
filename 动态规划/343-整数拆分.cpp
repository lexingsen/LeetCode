#include <vector>
#include <climits>
using namespace std;

/*
状态表示
f[n]
集合：长度为n的绳子至少剪1刀，最大乘积
属性：max
状态计算
最后一段为i
前面一段为n-i 剪f[n-i] 不剪n-i
f[n] = max(i * max(f[n - i], n - i)) i=1,2,...,n-1
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n + 1);
        f[0] = 0;
        int ans = INT_MIN;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; ++j) {
                f[i] = max(f[i], j * max(f[i - j], i - j));
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};