#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        return max(left, right) + 1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};