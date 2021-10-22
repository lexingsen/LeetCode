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
class Solution {
public:
    void dfs(TreeNode* root, vector<int> &data) {
        if (root) {
            dfs(root->left, data);
            data.emplace_back(root->val);
            dfs(root->right, data);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> data;
        dfs(root, data);
        for (int i = 1; i < data.size(); i++) {
            if (data[i] <= data[i - 1]) {
                return false;
            }
        }
        return true;
    }
};