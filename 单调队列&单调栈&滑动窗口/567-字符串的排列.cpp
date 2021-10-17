#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<int> c1(26);
        vector<int> c2(26);
        for (auto c: s1) {
            c1[c - 'a']++;
        }
        for (int i = 0; i < l2; i++) {
            // 收缩窗口
            if (i >= l1) {
                c2[s2[i - l1] - 'a']--;
            }
            c2[s2[i] - 'a']++;
            if (c1 == c2) {
                return true;
            }
        }
        return false;
    }
};