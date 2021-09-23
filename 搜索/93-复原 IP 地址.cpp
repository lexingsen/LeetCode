#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> ans;

void dfs(string &s, int index, int cnt, string path) {
  if (index == s.size() && cnt == 4) {
    ans.push_back(path.substr(1));
    return;
  }
  if (cnt > 4) {
    return;
  }
  if (s[index] == '0') {
    dfs(s, index+1, cnt+1, path+".0");
  } else {
    for (int i = index, t = 0; i < s.size(); ++i) {
      t = t*10 + s[i]-'0';
      if (t < 256) {
        dfs(s, i+1, cnt+1, path+"."+to_string(t));
      } else {
        break;
      }
    }
  }
}

vector<string> restoreIpAddresses(string s) {
  string path;
  dfs(s, 0, 0, path);

  return ans;
}