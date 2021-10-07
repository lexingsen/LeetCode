#include <vector>
#include <unordered_set>
using namespace std;

// 字符串查找
/*
trie
字符串哈希
kmp
*/

class Solution {
public:
    using ull = unsigned long long;
    const int P = 131;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<ull> hash;
        for (auto &word: wordDict) {
            ull h = 0;
            for (auto c:word) {
                h = h * P + c;
            }
            hash.insert(h);
        }
        int n = s.size();
        vector<bool> f(n + 1);
        f[0] = true;
        s = ' ' + s;
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                ull h = 0;
                for (int j = i + 1; j <= n; j++) {
                    h = h * P + s[j];
                    if (hash.count(h)) {
                        f[j] = true;
                    }
                }
            }
        }
        return f[n];
    }
};