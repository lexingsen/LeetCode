#include <vector>
#include <algorithm>
using namespace std;


/*
1.去重
2.选择首尾点以及极值点

*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int res = 0;
        for (int i = 1; i + 1 < nums.size(); i++) {
            int a = nums[i - 1];
            int b = nums[i];
            int c = nums[i + 1];
            if (a < b && c < b || a > b && c > b) {
                res++;
            }
        }
        return res;
    }
};