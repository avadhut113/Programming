#pragma once
#include "TreeNode.hpp"
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution637 {
public:
    static vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        vector<int> levelVals;
        int level = 0, levelCount = 1, nextLevelCount = 0;

        q.push(root);

        while (q.size() != 0) {
            TreeNode* cur = q.front();
            q.pop();

            levelVals.push_back(cur->val);

            levelCount--;

            if (cur->left != NULL) {
                q.push(cur->left);
                nextLevelCount++;
            }

            if (cur->right != NULL) {
                q.push(cur->right);
                nextLevelCount++;
            }

            if (levelCount == 0) {
                levelCount = nextLevelCount;
                nextLevelCount = 0;
                level++;
                double levelSum = accumulate(levelVals.begin(), levelVals.end(), 0.0);
                ans.push_back(levelSum / levelVals.size());
                levelVals.clear();
            }
        }

        return ans;
    }
};

/*void test637()
{
    TreeNode* root = new TreeNode(); root->val = 3;
    TreeNode* root1 = new TreeNode(); root1->val = 9;
    TreeNode* root2 = new TreeNode(); root2->val = 20;
    TreeNode* root21 = new TreeNode(); root21->val = 15;
    TreeNode* root22 = new TreeNode(); root22->val = 7;
    root->left = root1; root->right = root2;
    root2->left = root21; root2->right = root22;

    Solution637::averageOfLevels(root);
}*/
