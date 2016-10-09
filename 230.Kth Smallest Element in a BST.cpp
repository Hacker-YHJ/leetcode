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
  int kthSmallest(TreeNode* root, int k) {
    return helper(root, k);
  }
  int helper(TreeNode* r, int& k) {
    int ans;
    if (r->left) ans = helper(r->left, k);
    if (!k) return ans;
    if (!--k) return r->val;
    if (r->right) return helper(r->right, k);
    return -1;
  }
};
