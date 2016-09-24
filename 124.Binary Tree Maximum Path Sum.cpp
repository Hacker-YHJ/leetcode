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
private:
  int ans = numeric_limits<int>::min();
  int maxPathDownwards(TreeNode* root) {
    if (!root) return 0;
    int left = maxPathDownwards(root->left);
    int right = maxPathDownwards(root->right);
    ans = max(ans, (max(0, left) + max(0, right) + root->val));
    return root->val + max({0, left, right});
  }
public:
  int maxPathSum(TreeNode* root) {
    maxPathDownwards(root);
    return ans;
  }
};
