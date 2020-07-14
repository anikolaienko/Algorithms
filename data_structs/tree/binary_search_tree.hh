/**
 * Binary Search Tree
 */

#ifndef ALGORITHMS_BINARY_SEARCH_TREE
#define ALGORITHMS_BINARY_SEARCH_TREE

#include <string>
#include "../vector.hh"

namespace Algorithms {
    class BinarySearchTree {
        struct TreeNode {
            int val;
            TreeNode *left, *right;
        };

        TreeNode *head;

        void build(Vector& sorted_array);

        void clear(TreeNode *node);

    public:
        BinarySearchTree();

        BinarySearchTree(Vector& sorted_array);

        ~BinarySearchTree();

        std::string ToString();
    };
}

#endif // ALGORITHMS_BINARY_SEARCH_TREE