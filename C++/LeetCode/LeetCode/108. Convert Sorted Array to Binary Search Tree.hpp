#pragma once

#include "TreeNode.hpp"
#include <vector>

using namespace std;

class Solution108 {
public:

    static TreeNode* BuildTree(vector<int>& nums, int low, int high) {
        if (high - low + 1 < 1) return nullptr;

        int mid = (high + low) / 2;
        TreeNode* newnode = new TreeNode(nums[mid]);

        newnode->left = BuildTree(nums, low, mid - 1);
        newnode->right = BuildTree(nums, mid + 1, high);

        return newnode;
    }

    static TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        return BuildTree(nums, 0, nums.size() - 1);
    }
};

void test108()
{
    std::vector<int> vect{-10, -3, 0, 5, 9};
    TreeNode* newnode = Solution108::sortedArrayToBST(vect);
}