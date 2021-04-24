#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


vector<string> res;
  

void dfs(string& str, int index) {
  if (index == str.size()) {
    res.push_back(str);
    return ;
  }

  dfs(str, index+1);
  if (str[index] >= 'A') {
    str[index] ^= 32;
    dfs(str, index+1);
    str[index] ^= 32;
  }
  // if (islower(str[index])) {
  //   str[index] = toupper(str[index]);
  //   dfs(str, index+1);
  //   str[index] = tolower(str[index]);
  // }
  // else if (isupper(str[index])) {
  //   str[index] = tolower(str[index]);
  //   dfs(str, index+1);
  //   str[index] = toupper(str[index]);
  // }
}

vector<string> letterCasePermutation(string str) {
  if (!str.size()) {
    return res;
  }
  dfs(str, 0);
  return res;
}

int main() {
  string a = "a1b2";
  letterCasePermutation(a);
  for_each(res.begin(), res.end(), [](string x) {cout << x << " ";});
  cout << endl;
  return 0;
}