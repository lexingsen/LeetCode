#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


vector<string> ans;

class Solution {
public:
    vector<string> ans;
    void dfs(string& s, int u) {
        if (u == s.size()) {
            ans.emplace_back(s);
            return;
        } else {
            dfs(s, u + 1); // 不变换当前字母
            if (!isdigit(s[u])) {
                s[u] ^= 32;
                dfs(s, u + 1);
                s[u] ^= 32;
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};

int main() {
  string a = "a1b2";
  letterCasePermutation(a);
  for_each(res.begin(), res.end(), [](string x) {cout << x << " ";});
  cout << endl;
  return 0;
}