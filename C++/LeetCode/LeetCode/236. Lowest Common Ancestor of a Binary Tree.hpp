#pragma once
#include "TreeNode.hpp"
#include <print>

class Solution236 {
public:
    TreeNode* p, * q, * ans;

    bool recurseTree(TreeNode* cur) {
        if (cur == nullptr) return false;

        int mid = (int)(cur == p || cur == q);
        int left = (int)recurseTree(cur->left);
        int right = (int)recurseTree(cur->right);

        /*
        mid & left : current node is lca
        mid & right: current node is lca
        left& right: their parent, which is current node, is lca
        */
        if (mid + left + right >= 2) {
            ans = cur;
        }

        //if itself or one of its children is p or q's ancestor
        return mid + left + right > 0;
    };

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        recurseTree(root);
        return ans;
    }
};

void test236()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution236 sl;
    std::print("Lowest Common Ancestor of a Binary Tree : {} \n" , sl.lowestCommonAncestor(root, root->left, root->right)->val);
    std::print("Lowest Common Ancestor of a Binary Tree : {} \n", sl.lowestCommonAncestor(root, root->left, root->left->right->right)->val);
    std::print("Lowest Common Ancestor of a Binary Tree : {} \n", sl.lowestCommonAncestor(root, root, root->left->right->left)->val);
}