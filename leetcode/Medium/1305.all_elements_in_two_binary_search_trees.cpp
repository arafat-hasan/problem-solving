/*
 * FILE: 1305.all_elements_in_two_binary_search_trees.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
 * DATE CREATED: 26-01-22 17:08:45 (+06)
 * LAST MODIFIED: 26-01-22 17:13:16 (+06)
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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    solve(root1);
    solve(root2);
    sort(res.begin(), res.end());
    return res;
  }

 private:
  vector<int> res;
  void solve(TreeNode* root) {
    if (!root) return;
    res.push_back(root->val);
    solve(root->left);
    solve(root->right);
  }
};
