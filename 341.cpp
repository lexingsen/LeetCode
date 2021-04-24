#include <vector>
#include <string>
#include <istream>
using namespace std;

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;
   // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;
   // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};


vector<int> seq;
int cnt;

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
      dfs(nestedList);
    }

    void dfs(const vector<NestedInteger>& nestedList) {
      for (auto x: nestedList) {
        if (x.isInteger()) {
          seq.push_back(x.getInteger());
        } else {
          dfs(x.getList());
        }
      }
    }
    
    int next() {
      return seq[cnt ++];
    }
    
    bool hasNext() {
      return cnt < seq.size();
    }
};