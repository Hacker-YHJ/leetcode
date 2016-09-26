/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    return helper(root, false);
  }
  int helper(TreeNode* t, bool isLeft) {
    int res = 0;
    if (!t->left && !t->right) { res += isLeft ? t->val : 0; }
    else {
      if (t->left) res += helper(t->left, true);
      if (t->right) res += helper(t->right, false);
    }
    return res;
  }
};
