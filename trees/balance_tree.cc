#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* rotateRight(TreeNode* x, TreeNode* y, TreeNode* parent) {
        x->left = y->right;
        y->right = x;
        if (parent) {
            if (parent->left == x) parent->left = y;
            else parent->right = y;
        }
        return y;
    }
    
    TreeNode* rotateLeft(TreeNode* x, TreeNode* y, TreeNode* parent) {
        x->right = y->left;
        y->left = x;
        if (parent) {
            if (parent->left == x) parent->left = y;
            else parent->right = y;
        }
        return y;
    }
    
    TreeNode* balance(TreeNode* x, TreeNode* parent, int height) {
        if (height < 3) return x;
        
        int half = height >> 1, isLeft = !(x->left);
        for (int i = 0; i < half; ++i) {
            if (isLeft) x = rotateLeft(x, x->right, parent);
            else x = rotateRight(x, x->left, parent);
        }
        balance(x->right, x, height - 1 - half);
        balance(x->left, x, half);
        
        return x;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode *node = root, *parent = nullptr;
        int height = 0;

        while (node) {
            while (node->left) {
                node = rotateRight(node, node->left, parent);
            }
            if (!parent) root = node;
            parent = node;
            node = node->right;
            height++;
        }
        
        return balance(root, nullptr, height);
    }
};

void printTree(TreeNode* root) {
    vector<TreeNode*> stack, level;
    stack.push_back(root);
    
    while (stack.size()) {
        TreeNode* node = stack.back(); stack.pop_back();

        cout << node->val << " ";

        if (node->right) level.push_back(node->right);
        if (node->left) level.push_back(node->left);

        if (stack.empty()) {
            swap(stack, level);
            cout << endl;
        }
    }
}

int main() {
    TreeNode* root      = new TreeNode(4);
    root->left          = new TreeNode(2);
    root->right         = new TreeNode(6);
    root->left->left    = new TreeNode(1);
    root->left->right   = new TreeNode(3);
    root->right->left   = new TreeNode(5);
    root->right->right  = new TreeNode(7);

    Solution solution;
    root = solution.balanceBST(root);

    printTree(root);

    return 1;
}