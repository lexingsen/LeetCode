#include <vector>
#include <string>
#include <istream>
using namespace std;


// decode string 3[a]2[bc] aaabcbc
// 3[a2[c]]
string decodeString(string s) {
  string res;
  for (int i = 0; i < s.size(); ) {
    if (!isdigit(s[i])) {
      // 不是数字
      res += s[i ++];
    } else {
      int k = 0;
      while (isdigit(s[i])) {
        k = k * 10 + s[i] - '0';
        i ++;
      }
      // while结束，此时i索引指向的是'[' i+1指向的[后边的第一个字母
      int j = i + 1, sum = 1;
      while (sum > 0) {
        if (s[j] == '[') {
          sum ++;
        }
        if (s[j] == ']') {
          sum ++;
        }
        j ++;
      }
      string r = decodeString(s.substr(i+1, j-i-2));
      while (k --) {
        res += r;
      }
      i = j;
    }
  }
}