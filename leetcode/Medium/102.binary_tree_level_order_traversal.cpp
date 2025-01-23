/*
 * FILE: 102.binary_tree_level_order_traversal.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * DATE CREATED: 16-01-22 15:45:39 (+06)
 * LAST MODIFIED: 16-01-22 15:46:10 (+06)
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (root == NULL) return ret;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int levelSize = (int)q.size();
      vector<int> subVector;

      for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = q.front();
        subVector.push_back(node->val);
        q.pop();
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
      }

      ret.push_back(subVector);
    }
    return ret;
  }
};
