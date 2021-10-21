#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c: s) {
            if (c == '[' || c == '{' || c == '(') {
                st.push(c);
            } else if (st.empty()) {
                // 说明没有左边括号
                return false;
            } else if ((st.top() == '(' && c == ')') || (st.top() == '{' && c == '}') || (st.top() == '[' && c == ']')) {
                st.pop();
            } else {
                // stack st['[']
                return false;
            }
        }
        return st.empty();
    }
};