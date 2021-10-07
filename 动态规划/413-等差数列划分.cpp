#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        // 构造差分数组
        vector<int> diff(n);
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
        // [L, R] 是一个等差数组
        // 在对应的差分数组中 [L+1, R] 这个区间是连续相同的
        int ans = 0;
        for (int i = 1; i < diff.size(); i++) {
            int j = i;
            while (j < diff.size() && diff[j] == diff[i]) {
                j++;
            }
            int k = j - i;
            ans += (k - 1) * k / 2;
            i = j - 1;
        }
        return ans;
    }
};