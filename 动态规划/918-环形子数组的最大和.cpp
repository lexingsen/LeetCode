#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(2 * n + 1);
        // 预处理前缀和数组
        for (int i = 1; i <= 2 * n; i++) {
            s[i] = s[i - 1] + nums[(i - 1) % n];
        }
        int res = INT_MIN;
        deque<int> q; // 维护一个长度为<=n的单调队列
        q.push_front(0);
        for (int i = 1; i <= 2 * n; i++) {
            while (q.size() && i - q.front() > n) {
                q.pop_front();
            }
            res = max(res, s[i] - s[q.front()]);
            while (q.size() && s[q.back()] >= s[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return res;
    }
};