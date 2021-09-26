/*
斐波那契数列变形题目
优化时间复杂度为O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        // 1.n == 1
        if (n == 1) {
            return 1;
        }
        // 2.n == 2
        if (n == 2) {
            return 2;
        }

        int a = 1;
        int b = 2;
        // 3.n >= 3
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};