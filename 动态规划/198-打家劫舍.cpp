class Solution {
public:
    int rob(vector<int>& nums) {
        // f[i]表示偷1-n家的最大值
        int n = nums.size();
        vector<int> f(n + 1, 0);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            // 第i家偷
            f[i] = nums[i - 1];
            if (i >= 2) {
                f[i] += f[i - 2];
            }
            // 第i家不投 f[i] = f[i - 1]
            f[i] = max(f[i], f[i - 1]);
        }
        return f[n];
    }
};