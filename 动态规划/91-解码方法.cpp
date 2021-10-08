#include <string>
#include <vector>
using namespace std;

/*
状态表示
集合：f[i]表示所有由前i个字符可以解码成字符串的集合
属性：数量


状态计算
f[0] = 1
将集合划分为两种
(1)解码后的字符串最后一个字符对应一个数字 合法方案(1-9)   f[i] += f[i - 1];
(2)解码后的字符串最后一个字符对应两个数字 合法方案(10-26)   f[i] += f[i - 2];
f[i] = f[i - 1] + f[i - 2]

*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        s = ' ' + s;
        for (int i = 1; i <= n; i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                f[i] += f[i - 1];
            }
            if (i >= 2) {
                int t = s[i] - '0' + (s[i - 1] - '0') * 10;
                if (t >= 10 && t <= 26) {
                    f[i] += f[i - 2];
                }
            }
        }
        return f[n];
    }
};