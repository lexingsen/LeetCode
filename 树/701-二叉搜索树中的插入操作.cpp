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
    TreeNode* dfs(TreeNode* &root, int val) {
        if (root) {
            if (root->val == val) {
                root->val = val;
            } else if (val < root->val) {
                root->left = dfs(root->left, val);
            } else if (val > root->val) {
                root->right = dfs(root->right, val);
            }
            return root;
        }
        root = new TreeNode(val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
};