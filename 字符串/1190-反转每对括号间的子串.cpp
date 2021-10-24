#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void reverse(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    string reverseParentheses(string s) {
        if (!s.size()) {
            return s;
        }
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                reverse(s, st.top() + 1, i - 1);
                st.pop();
            }
        }

        string ans = "";
        for (auto c : s) {
            if (c == '(' || c == ')') {
                continue;
            }
            ans += c;
        }
        return ans;
    }
};