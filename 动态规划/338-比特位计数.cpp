#include <vector>
using namespace std;


/*

f[i] 表示i这个数字二进制表示中 1的个数

如：10001101 可以看作是 i>>1:1000110 和 最后以为是否为1来递推
f[i] = f[i>>1] + (i&1)
*/


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);
        f[0] = 0; // base case: 0的二进制表示中1的个数为0
        for (int i = 1; i <= n; i++) {
            f[i] = f[i>>1] + (i & 1);
        }
        return f;
    }
};