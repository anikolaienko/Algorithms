#include "binary_search_tree.hh"

namespace Algorithms {
    BinarySearchTree::BinarySearchTree() { }

    BinarySearchTree::BinarySearchTree(Vector sorted_array) {
        build(sorted_array);
    }

    BinarySearchTree::~BinarySearchTree() {
        if (!head) return;
        clear(head);
    }

    void BinarySearchTree::build(Vector& sorted_array) {
        
    }

    void BinarySearchTree::clear(TreeNode *node) {

    }

    std::string BinarySearchTree::ToString() {

    }
}