/*
 * FILE: 112.path_sum.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/path-sum/
 * DATE CREATED: 17-01-22 01:06:35 (+06)
 * LAST MODIFIED: 18-01-22 00:22:36 (+06)
 * VERDICT: Accepetd
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    return root != NULL && helper(root, targetSum);
  }

  bool helper(TreeNode* root, int targetSum) {
    if (!root) return false;
    targetSum -= root->val;
    if (!root->left && !root->right) {
      return targetSum == 0;
    }
    return helper(root->left, targetSum) || helper(root->right, targetSum);
  }
};
