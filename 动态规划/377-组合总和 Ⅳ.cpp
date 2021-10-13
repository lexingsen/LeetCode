#include <vector>
using namespace std;

/*
有顺序不能使用背包
背包问题：有限制条件下的组合问题
*/

/*
状态表示
f[i]
集合：i的所有划分方案的集合   i=4  i=2+2 i=1+3 i=3+1
属性：数量
状态计算 (对应集合的划分 不重不漏)
取决于nums的大小 假设为n
a1 a2 a3 ... aj ... an
f[j] = f[i - a[j]]
*/
class Solution {
public:
    // 完全背包求方案数
    int combinationSum4(vector<int>& nums, int m) {
        vector<unsigned> f(m + 1);
        f[0] = 1;
        for (int i = 1; i <= m; i++) {
            for (auto j:nums) {
                if (i >= j) {
                    f[i] += f[i - j];
                }
            }
        }
        return f[m];
    }
};