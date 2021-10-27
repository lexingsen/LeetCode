#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


vector<vector<int>> res;
/*
para
path:记录组合的子集
start:从哪一个数字开始搜
end:最后一个可以被数字
k:还能被添加进去的数字
*/
void dfs(vector<int>& path, int start, int end, int k) {
  if (!k) {
    res.push_back(path);
    return ;
  }
  for (int i = start; i <= end; ++i) {
    path.push_back(i);
    dfs(path, i+1, end, k-1);
    path.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  if (n <= 0 || k <= 0) {
    return res;
  }
  vector<int> path;
  dfs(path, 1, n, k);
  return res;
}

int main() {
  vector<vector<int>> ans = combine(4, 2);
  for (auto x:ans) {
    for (auto y:x) {
      cout << y << " ";
    }
    cout << endl;
  }
}