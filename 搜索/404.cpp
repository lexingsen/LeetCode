class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        // 左叶子
        if ((root->left && !root->left->left && !root->left->right)) {
            res += root->left->val;
        }
        return dfs(root->left) + dfs(root->right) + res;    
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return dfs(root);
    } 
};


