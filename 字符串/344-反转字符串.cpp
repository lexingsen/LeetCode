#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (!s.size()) {
            return;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};