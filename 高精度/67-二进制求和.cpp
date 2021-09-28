#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0) {
            int da = i >= 0 ? a[i--] - '0' : 0;
            int db = j >= 0 ? b[j--] - '0' : 0;
            int sum = da + db + carry;
            res += to_string(sum % 2);
            carry = sum / 2;
        }
        if (carry) {
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};