#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (--n) {
                auto x = q.front();q.pop();
                auto y = q.front();
                x->next = y;
                if (x->left) {
                    q.push(x->left);
                }
                if (x->right) {
                    q.push(x->right);
                }
            }
            auto x = q.front();q.pop();
            x->next = NULL;
            if (x->left) {
                q.push(x->left);
            }
            if (x->right) {
                q.push(x->right);
            }
        }
        return root;
    }
};