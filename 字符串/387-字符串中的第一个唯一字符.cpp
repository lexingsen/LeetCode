#include <climits>
#include <string>
using namespace std;

class Solution {
public:

    int firstUniqChar(string s) {
        int hash[26] = {0};
        for (auto c: s) {
            hash[c - 'a']++;
        }

        int res = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a'] == 1) {
                res = min(res, i);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};