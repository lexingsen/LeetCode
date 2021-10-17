#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (auto c : magazine) {
            hash[c - 'a']++;
        }
        for (auto c : ransomNote) {
            if (!hash[c - 'a']) {
                return false;
            }
            hash[c - 'a']--;
        }
        return true;
    }
};