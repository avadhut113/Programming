#pragma once
#include "TreeNode.hpp"

class Solution129 {
public:
    static int sumNumbers(TreeNode* root, int initval) {
        if (root == nullptr)
            return 0;

        if (!root->left && !root->right)
            return root->val + initval;

        int leftsum = sumNumbers(root->left, (initval + root->val) * 10);
        int rightsum = sumNumbers(root->right, (initval + root->val) * 10);
        return leftsum + rightsum;
    }

    static int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};

void test129()
{
    TreeNode* root = new TreeNode(); root->val = 4;
    TreeNode* root1 = new TreeNode(); root1->val = 9;
    TreeNode* root2 = new TreeNode(); root2->val = 0;
    TreeNode* root11 = new TreeNode(); root11->val = 5;
    TreeNode* root12 = new TreeNode(); root12->val = 1;
    root->left = root1; root->right = root2;
    root1->left = root11; root1->right = root12;

    Solution129::sumNumbers(root);
}