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
    vector<int> data;
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            data.emplace_back(root->val);
            dfs(root->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int i = 0;
        int j = data.size() - 1;
        while (i < j) {
            if (data[i] + data[j] == k) {
                return true;
            } else if (data[i] + data[j] < k) {
                i++;
            } else if (data[i] + data[j] > k) {
                j--;
            }
        }
        return false;
    }
};