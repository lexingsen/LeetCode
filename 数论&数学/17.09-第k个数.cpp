class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> f(k + 1);
        f[0] = 1;
        int idx = 1;
        int p3 = 0;
        int p5 = 0;
        int p7 = 0;
        for (int i = 1; i <= k; i++) {
            int a = f[p3] * 3;
            int b = f[p5] * 5;
            int c = f[p7] * 7;
            int mi = min(a, min(b, c));
            if (mi == a) {
                p3++;
            }
            if (mi == b) {
                p5++;
            }
            if (mi == c) {
                p7++;
            }
            f[idx++] = mi;
        }
        return f[k - 1];
    }
};