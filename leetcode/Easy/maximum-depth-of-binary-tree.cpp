/*
 * FILE: maximum-depth-of-binary-tree.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * DATE CREATED: 03-02-21 18:35:48 (+06)
 * LAST MODIFIED: 03-02-21 18:38:11 (+06)
 * VERDICT: Accepetd
 * VERSION: 1.0
 * DESCRIPTION: Deleted code is debugged code.
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
  int maxDepth(TreeNode* root) { return solve(root); }

 private:
  int solve(TreeNode* root) {
    if (root == NULL) return 0;
    return max(solve(root->left), solve(root->right)) + 1;
  }
};
