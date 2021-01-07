/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  private:
    int sum = 0;
  public:
    int rangeSumBST(TreeNode* root, int low, int high) {
      if(!root) return 0;
      if(root->val >= low and root->val <= high) sum += root->val;
      if(root->val > low) rangeSumBST(root->left, low, high);
      if(root->val < high) rangeSumBST(root->right, low, high);
      return sum;
    }
};
