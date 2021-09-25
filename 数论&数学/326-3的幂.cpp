class Solution {
public:
    bool isPowerOfThree(int n) {
        if (!n) {
            return false;
        }
        while (n) {
            if (n == 1) {
                return true;
            }
            if (n % 3 == 0) {
                n /= 3;
            } else {
                return false;
            }
        }
        return true;
    }
};