#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template <typename T>
using vvt = vector<vector<T>>;

template <typename T>
using vt = vector<T>;

vvt<int> dfs(vvt<int>& image, int sr, int sc, int newColor) {
  if (!image.size() || !image[0].size()) {
    return image;
  }
  int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
  int oldColor = image[sr][sc];
  image[sr][sc] = newColor;
  for (int i = 0; i < 4; ++i) {
    int x = sr+dx[i], y = sc+dy[i];
    if (x >= 0 && x < image.size() && y < image[0].size() && y >= 0 && image[x][y] == oldColor) {
      dfs(image, x, y, newColor);
    }
  }
  return image;
}

int main() {

  return 0;
}