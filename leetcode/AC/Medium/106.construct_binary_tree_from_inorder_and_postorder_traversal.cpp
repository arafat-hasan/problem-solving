/*
 * FILE: 106.construct_binary_tree_from_inorder_and_postorder_traversal.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * DATE CREATED: 20-01-22 01:38:17 (+06)
 * LAST MODIFIED: 20-01-22 03:15:05 (+06)
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return Tree(inorder, 0, (int)inorder.size() - 1, postorder, 0,
                (int)postorder.size() - 1);
  }

 private:
  TreeNode *Tree(vector<int> &inorder, int inLow, int inHigh,
                 vector<int> &postorder, int poLow, int poHigh) {
    if (inLow > inHigh || poLow > poHigh) return nullptr;
    TreeNode *node = new TreeNode(postorder[poHigh]);
    int inIdx = inLow;
    while (inorder[inIdx] != postorder[poHigh]) inIdx++;
    node->left = Tree(inorder, inLow, inIdx - 1, postorder, poLow,
                      poLow + inIdx - inLow - 1);
    node->right = Tree(inorder, inIdx + 1, inHigh, postorder,
                       poLow + inIdx - inLow, poHigh - 1);
    return node;
  }
};
