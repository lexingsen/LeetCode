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
    bool dfs(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return sum - root->val == 0;
        }

        sum -= root->val;
        auto left = dfs(root->left, sum);
        auto right = dfs(root->right, sum);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = targetSum;
        return dfs(root, sum);
    }
};