#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash1[26] = {0};
        int hash2[26] = {0};
        for (auto c: s) {
            hash1[c - 'a']++;
        }

        for (auto c: t) {
            hash2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (hash2[i] != hash1[i]) {
                return false;
            }
        }
        return true;
    }
};