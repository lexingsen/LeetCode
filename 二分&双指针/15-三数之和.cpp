#include <vector>
#include <algorithm>
using namespace std;



/*
双指针，遵循单调性
固定一个i  a[i]=c

sum=c+nums[i]+nums[j] > 0 为了靠近0,sum需要减少,由单调性,需要j--
sum=c+nums[i]+nums[j] < 0 为了靠近0,sum需要增加,由单调性,需要i++
sum=c+nums[i]+nums[j] = 0 i++,j-- 并且需要去掉[i+1, j-1]这个区间中和 nums[i]相同 以及和nums[j]相同的元素
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 三数之和 至少都需要有三个数字
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (i && nums[i]==nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j]==nums[j+1]) {
                        j++;
                    }
                    while (j < k && nums[k]==nums[k-1]) {
                        k--;
                    }
                    // 不重复的话
                    j++;
                    j--;

                } else if (x < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            
        }
        return ans;
    }
};