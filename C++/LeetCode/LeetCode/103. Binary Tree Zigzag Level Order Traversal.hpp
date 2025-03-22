#pragma once
#include "TreeNode.hpp"
#include <vector>
#include <stack>

using namespace std;

class Solution103 {
public:
    static vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) return ans;

        stack<TreeNode*> stk, stk_next;
        TreeNode* cur;
        bool pos = true;

        stk.push(root);
        while (!stk.empty()) {
            int levelSize = stk.size();
            vector<int> level(levelSize);
            bool next_pos = !pos;

            for (int i = 0; i < levelSize; ++i) {
                cur = stk.top(); stk.pop();
                level[i] = cur->val;

                TreeNode* child1 = cur->left;
                TreeNode* child2 = cur->right;

                if (next_pos) {
                    /*
                    if next_pos is true, we go from left to right,
                    so right child should be pushed into stack earlier
                    */
                    swap(child1, child2);
                }

                if (child1) stk_next.push(child1);
                if (child2) stk_next.push(child2);

            }

            swap(stk, stk_next);
            pos = next_pos;
            ans.push_back(level);
        }

        return ans;
    }
};

void test103()
{
    TreeNode* root = new TreeNode(); root->val = 1;
    TreeNode* root1 = new TreeNode(); root1->val = 2;
    TreeNode* root2 = new TreeNode(); root2->val = 3;
    TreeNode* root11 = new TreeNode(); root11->val = 4;
    TreeNode* root12 = new TreeNode(); root12->val = 5;
    TreeNode* root21 = new TreeNode(); root21->val = 6;
    TreeNode* root22 = new TreeNode(); root22->val = 7;
   
    root->left = root1; root->right = root2;
    root1->left = root11;root1->right = root12;
    root2->left = root21;root2->right = root22;

    Solution103::zigzagLevelOrder(root);
}