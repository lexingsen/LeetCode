#include <vector>
#include <climits>
using namespace std;



/*
i < j
状态表示
left:表示左半部分的最大最大值
a[i]+i

右半边部分的最大值
a[j]-j
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        // a[i]+i  a[j]-j;
        int left = a[0];
        int res = INT_MIN;
        for (int i = 1; i < a.size(); i++) {
            res = max(res, left + a[i] - i);
            left = max(left, a[i] + i);
        }
        return res;
    }
};