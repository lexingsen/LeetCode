#include <vector>
#include <string>
#include <istream>
using namespace std;

vector<char> allows[7][7];

bool dfs(string& last, string now) {
  if (last.size() == 1) {
    return true;
  }
  if (now.size()+1 == last.size()) {
    return dfs(now, "");
  }
  int a = last[now.size()]-'A', b = last[now.size()+1] - 'A';
  for (auto c: allows[a][b]) {
    if (dfs(last, now+c)) {
      return true;
    }
  }
  return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
  for (auto allow:allowed) {
    int a = allow[0]-'A';
    int b = allow[1]-'B';
    int c = allow[2];
    allows[a][b].push_back(c);
  }
  return  dfs(bottom, "");
}