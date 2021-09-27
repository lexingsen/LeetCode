#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
考虑一个局部
    u
   / \
  x   y
f[u][0] = max(f[x][0], f[x][1]) + max(f[y][0], f[y][1])
f[u][1] = f[x][0] + f[y][0] + Wu
res = max(f[u][0], f[u][1])
*/

class Solution {
public:
    int rob(TreeNode* root) {
        auto f = dfs(root);
        return max(f[0], f[1]);
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto x = dfs(root->left);
        auto y = dfs(root->right);

        return {max(x[0], x[1]) + max(y[0], y[1]), x[0] + y[0] + root->val};
    }
};