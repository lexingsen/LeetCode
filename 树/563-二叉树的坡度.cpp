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
    int findTilt(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        auto left = sum(root->left);
        auto right = sum(root->right);
        ans += abs(left - right);
        ans += (findTilt(root->left) + findTilt(root->right));
        return ans;
    }


    int sum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        ans += root->val;
        ans += sum(root->left);
        ans += sum(root->right);
        return ans;
    }
};