#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int lmx = height[l];
        int rmx = height[r];

        int ans = 0;
        while (l < r) { 
            if (height[l] <= height[r]) {
                lmx = max(lmx, height[l]);
                ans += (lmx - height[l]);
                l++;
            } else {
                rmx = max(rmx, height[r]);
                ans += (rmx - height[r]);
                r--;
            }
        }
        return ans;
    }
};