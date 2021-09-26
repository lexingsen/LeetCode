#include <vector>
#include <climits>
#include <cstring>
using namespace std;


/*
状态表示 
f[i][0]:第i个数字不选，。从第0到第n-1获得的最大值
f[i][1]:第i个数字选，。从第0到第n-1获得的最大值

状态计算
f[i][1]  第i-1个数字必然不选，并且i是重复的
f[i][1] = f[i - 1][0] + i * cnt[i]


f[i][0] = max(f[i-1][1], f[i-1][0])

*/

const int N = 1e5+10;
int cnt[N];
int f[N][2];
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(cnt, 0, sizeof(cnt));
        memset(f, 0, sizeof(f));
        for (auto c: nums) {
            cnt[c]++;
        }
        int res = 0;
        for (int i = 1; i < N; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + i * cnt[i];

            res = max(res, max(f[i][0], f[i][1]));
        }
        return res;
    }
};