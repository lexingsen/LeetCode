#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_map<int, int> window;
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            right++;
            while (window[c] > 1) {
                char d = s[left];
                window[d]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};