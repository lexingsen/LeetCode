#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bf(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j = 0;
                i = ++k;
            }
        }
        return j == m;
    }
    vector<string> stringMatching(vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        vector<string> ans;
        set<string> st;
        sort(words.begin(), words.end(), [] (auto x, auto y) {
            if (x.size() != y.size()) {
                return x.size() < y.size();
            }
            return x < y;
        });
        #ifdef ON
        for_each(words.begin(), words.end(), [] (auto x) {cout << x << " ";});
        cout << endl;
        #endif
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (bf(words[j], words[i])) {
                    st.emplace(words[i]);
                }
            }
        }
        for (auto s: st) {
            ans.emplace_back(s);
        }
        return ans;
    }
};