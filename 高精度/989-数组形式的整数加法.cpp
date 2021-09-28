#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int> res;
        vector<int> b;
        while (k) {
            b.push_back(k % 10);
            k /= 10;
        }
        reverse(b.begin(), b.end());
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0  || j >= 0) {
            int fa = i >= 0 ? a[i--] : 0;
            int fb = j >= 0 ? b[j--] : 0;
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