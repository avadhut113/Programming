#include "TreeNode.hpp"

class Solution114 {
public:
    // Function to flatten a binary tree into a linked list in-place.
    static void flatten(TreeNode* root) {
        // Continue flattening the tree until we have processed all nodes.
        while (root) {
            // Check if the current node has a left child.
            if (root->left) {
                // Find the rightmost node in the left subtree.
                TreeNode* rightMost = root->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }

                // Attach the right subtree of the current node to the rightmost node.
                rightMost->right = root->right;

                // Move the left subtree under the current node to the right.
                root->right = root->left;

                // Set the left child of the current node to nullptr.
                root->left = nullptr;
            }

            // Move on to the right child of the current node.
            root = root->right;
        }
    }
};

void test114()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution114::flatten(root);
}