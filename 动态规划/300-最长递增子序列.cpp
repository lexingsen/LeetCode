#include <vector>
#include <iostream>
using namespace std;



/*
动态规划：
f[i] 表示vector<int> a[0...i] 上升子序列的最大长度
状态转移
    a[i] > {a[i-1], a[i-2], ... , a[2], a[1], a[0]} 时，f[i] = f[i-1] + 1
    f[i] = f[i-1]

*/


/*
贪心+二分
对于一个上升子序列，其结尾元素越小，越有利于在后面接其他的元素，也就越可能变得更长
tail[i]表示长度为i的所有最长上升子序列结尾的最小值

1 3 4 2
tail[1] = 1
tail[2] = 3
tail[3] = 4
tail[4] 
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < f.size(); i++) {
            res = max(res, f[i]);
        }
        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        vector<int> tail(n+1, 0);
        int len = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int l = 0;
            int r = len;
            while (l < r) {
                int m = l + r + 1 >> 1;
                if (tail[m] < x) {
                    l = m;
                } else {
                    r = m - 1;
                }
                tail[l+1] = x;
                len = max(len, l+1);
            }
        }
        return len;
    }
};


int main() {
    Solution sol;
    vector<int> a = {10,9,2,5,3,7,101,18};
    sol.lengthOfLIS()
}