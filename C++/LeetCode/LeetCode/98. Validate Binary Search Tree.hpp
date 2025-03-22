#pragma once
#include "TreeNode.hpp"
#include <limits>

class Solution98 {
public:
    //some test case failed
     /*bool isValidBST(TreeNode* root) {
         if(!root) return true;
         if(root->left && root->left->val >= root->val) return false;
         if(root->right && root->right->val <= root->val) return false;

         return isValidBST(root->left) && isValidBST(root->right);
     }*/

    bool inOrder(TreeNode* node, long long& last) {
        if (!node) return true;
        if (!inOrder(node->left, last)) return false;

        if (node->val <= last) return false;
        last = node->val;

        if (!inOrder(node->right, last)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        long long last = LLONG_MIN;
        return inOrder(root, last);
    }
};

void test98()
{
    Solution98 sl;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    sl.isValidBST(root);
}