/*
 * FILE: 105.construct_binary_tree_from_preorder_and_inorder_traversal.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * DATE CREATED: 20-01-22 16:40:41 (+06)
 * LAST MODIFIED: 20-01-22 17:03:46 (+06)
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return tree(preorder, 0, (int)preorder.size() - 1, inorder, 0,
                (int)inorder.size() - 1);
  }

 private:
  TreeNode* tree(vector<int>& preorder, int preorderLow, int preorderHigh,
                 vector<int>& inorder, int inorderLow, int inorderHigh) {
    if (preorderLow > preorderHigh || inorderLow > inorderHigh) return nullptr;
    TreeNode* node = new TreeNode(preorder[preorderLow]);
    int inorderIdx = inorderLow;
    while (preorder[preorderLow] != inorder[inorderIdx]) inorderIdx++;
    node->left =
        tree(preorder, preorderLow + 1, preorderLow + inorderIdx - inorderLow,
             inorder, inorderLow, inorderIdx - 1);
    node->right = tree(preorder, preorderLow + inorderIdx - inorderLow + 1,
                       preorderHigh, inorder, inorderIdx + 1, inorderHigh);
    return node;
  }
};
