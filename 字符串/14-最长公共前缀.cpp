#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        // 如果存在公共前缀 那么一定存在于字典序最小和字典序最大的字符串当中
        int n = s.size();
        sort(s.begin(), s.end());// O(nlogn) + O(n) = O(nlogn) 核心
        string st = s[0];        // 字典序最小
        string ed = s[n - 1];    // 字典序最大
        int len = min(st.size(), ed.size());

        int i = 0;
        while (i < len && st[i] == ed[i]) {
            i++;
        }
        // for (i = 0; i < len && st[i] == ed[i]; i++);//O(n)
        return st.substr(0, i);
    }
};