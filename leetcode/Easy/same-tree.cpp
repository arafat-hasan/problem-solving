/*
 * FILE: same-tree.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/same-tree/
 * DATE CREATED: 03-02-21 17:13:34 (+06)
 * LAST MODIFIED: 03-02-21 18:01:24 (+06)
 * VERDICT:
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL or q == NULL) return p == q;
    return p->val == q->val and isSameTree(p->left, q->left) and
           isSameTree(p->right, q->right);
  }
};

