class Solution {
public:
    #define N (5000010)
    int primes[N];
    int idx = 0;
    bool st[N];
    int countPrimes(int n) {
        memset(st, false, sizeof(st));
        for (int i = 2; i < n; i++) {
            if (st[i]) {
                continue;
            }
            primes[idx++] = i;
            for (int j = i + i; j < n; j += i) {
                st[j] = true;
            }
        }
        return idx;
    }
};