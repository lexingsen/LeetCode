#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    using vi = vector<int>;
    vi mul(vi& a, vi& b) {
        int n = a.size();
        int m = b.size();
        vi c(n + m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        int t = 0;
        for (int i = 0; i < c.size(); i++) {
            t += c[i];
            c[i] = t % 10;
            t /= 10;
        }
        while (c.size() > 1 && c.back() == 0) {
            c.pop_back();
        }

        return c;
    }
    string multiply(string num1, string num2) {
        vi a(num1.size()), b(num2.size());
        for (auto x: num1) {
            a.push_back(x - '0');
        }
        for (auto x: num2) {
            b.push_back(x - '0');
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vi c = mul(a, b);
        string res = "";
        for (int i = c.size() - 1; i >= 0; i--) {
            res += (c[i] + '0');
        }
        return res;
    }
};