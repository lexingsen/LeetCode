#include <vector>
#include <string>
#include <istream>
using namespace std;


struct TreeNode {
  int val;
  TreeNode* left, *right;

  TreeNode(int val):val(val), left(nullptr), right(nullptr) {

  }
};

vector<TreeNode*> dfs(int l, int r) {
  vector<TreeNode*> res;
  if (l > r) {
    res.push_back(nullptr);
    return res;
  }
  for (int i = l; i <= r; ++i) {
    auto left = dfs(l, i-1);
    auto right = dfs(i+1, r);
    for (auto& lt: left) {
      for (auto& rt: right) {
        auto root = new TreeNode(i);
        root->left = lt;
        root->right = rt;
        res.push_back(root);
      }
    }
  }
}

vector<TreeNode*> generateTrees(int n) {
  if (!n) {
    return vector<TreeNode*>();
  }
  return dfs(1, n);
}

int main() {
  return 0;
}