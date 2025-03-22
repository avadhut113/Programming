#include "TreeNode.hpp"

class Solution239 {

    int k;
    int kthsmall{ -1 };

    void inOrder(TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        if (--k == 0) kthsmall = node->val;
        inOrder(node->right);
    };

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inOrder(root);
        return kthsmall;
    }
};

void test239()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);



    Solution239 sl;
    sl.kthSmallest(root, 3);
}