/*
 * FILE: symmetric-tree.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * DATE CREATED: 03-02-21 18:44:17 (+06)
 * LAST MODIFIED: 03-02-21 22:00:10 (+06)
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
  bool isSymmetric(TreeNode* root) {
    return root == NULL or solve(root->left, root->right);
  }

  bool solve(TreeNode* left, TreeNode* right) {
    if (left == NULL or right == NULL) {
      return left == right;
    }
    if (left->val != right->val) {
      return false;
    }

    return solve(left->left, right->right) and solve(left->right, right->left);
  }
};
