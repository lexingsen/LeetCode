#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int j = 1;
        int carry = 0;
        vector<int> res;
        while (i >= 0) {
            int fa = digits[i--];
            int fb = j-- == 1 ? 1 : 0;
            int sum = fa + fb + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};