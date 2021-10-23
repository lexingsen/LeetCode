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
    void swap(TreeNode* &left, TreeNode* &right) {
        TreeNode* t = left;
        left = right;
        right = t;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        
        return root;
    }
};