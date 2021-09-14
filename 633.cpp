class Solution {
public:
    
    bool judgeSquareSum(int c) {
        
        for (long long i = 0; i*i <= c; i++) {
            int b = c - i*i;
            int r = sqrt(b);
            if (r*r == b) {
                return true;
            }
        }
        return false;
    }
};