#pragma once
#include "TreeNode.hpp"
#include <vector>
#include <queue>

using namespace std;

class Solution199 {
public:
    static vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            int level_last;

            while (level_size--) {
                TreeNode* cur = q.front(); q.pop();

                level_last = cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            ans.push_back(level_last);
        }

        return ans;
    }
};

void test199()
{
    TreeNode* root = new TreeNode(); root->val = 1;
    TreeNode* root1 = new TreeNode(); root1->val = 2;
    TreeNode* root2 = new TreeNode(); root2->val = 3;
    TreeNode* root12 = new TreeNode(); root12->val = 5;
    TreeNode* root22 = new TreeNode(); root22->val = 4;
    root->left = root1; root->right = root2;
    root1->right = root12;
    root2->right = root22;

    Solution199::rightSideView(root);
}