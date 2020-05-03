#include <iostream>

class Tree {
public:
    class TreeNode {
    public:
        TreeNode *left, *right, *parent;
        int val;
    };

    TreeNode *root;
};

using TreeNode = Tree::TreeNode;

void inorder(TreeNode *node) {
    if (node) {
        inorder(node->left);
        std::cout << node->val << std::endl;
        inorder(node->right);
    }
}

TreeNode* getMin(TreeNode *node) {
    if (node->left) node = node->left;
    return node;
}

TreeNode* getSuccessor(TreeNode *node) {
    if (node->right) return getMin(node);
    TreeNode *p = node->parent;
    while (p && p->right == node) {
        node = p;
        p = p->parent;
    }
    return p;
}

void insert(Tree tree, TreeNode *newNode) {
    TreeNode *parent = NULL, *node = tree.root;
    while (node) {
        parent = node;
        node = (newNode->val < node->val) ? node->left : node->right;
    }
    newNode->parent = parent;
    if (!parent) tree.root = newNode;
    else if (parent->val > newNode->val) parent->left = newNode;
    else parent->right = newNode;
}

// Replaces the subtree rooted at u with subtree rooted at v
void transplant(Tree tree, TreeNode *u, TreeNode *v) {
    if (!u->parent) tree.root = v;
    else if (u->parent->left == u) u->parent->left = v;
    else u->parent->right = v;

    if (v != NULL) v->parent = u->parent;
}

void remove(Tree tree, TreeNode *z) {
    if (!z->left) transplant(tree, z, z->right);
    else if (!z->right) transplant(tree, z, z->left);
    else {
        TreeNode* y = getMin(z->right);
        if (y->parent != z) {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}