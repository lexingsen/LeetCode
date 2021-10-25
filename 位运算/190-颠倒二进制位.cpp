#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = "";
        while (n) {
            s += to_string(n % 2);
            n /= 2;
        }
        
        uint32_t len = s.size();
        if (len < 32) {
            for (int i = 0; i < 32 - len; i++) {
                s += to_string(0);
            }
        }
        uint32_t ans = 0;
        int p = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            ans += (s[i] - '0') * pow(2, p++);
        }
        
        return ans;
    }
};