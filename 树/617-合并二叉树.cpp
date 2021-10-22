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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2) {
            return root2;
        }
        if (!root2 && root1) {
            return root1;
        }
        if (!root1 && !root2) {
            return nullptr;
        }
        return dfs(root1, root2);
    }

    TreeNode* dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        if (root1 && root2) {
            root->val = (root1->val + root2->val);
            root->left = dfs(root1->left, root2->left);
            root->right = dfs(root1->right, root2->right);
        } else if (root1 && !root2) {
            root = root1;
            root->left = root1->left;
            root->right = root1->right;
        } else if (root2 && !root1) {
            root = root2;
            root->left = root2->left;
            root->right = root2->right;
        }
        return root;
    }
};