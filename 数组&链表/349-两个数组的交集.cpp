#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end()); 
        vector<int> ans;
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                ans.emplace_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        set<int> st;
        for (auto s: ans) {
            st.insert(s);
        }
        ans.clear();
        for (auto s:st) {
            ans.emplace_back(s);
        }
        return ans;
    }
};