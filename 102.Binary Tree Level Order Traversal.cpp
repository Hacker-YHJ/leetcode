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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> res;
    deque<TreeNode*> q;
    q.push_back(root);
    while (!q.empty()) {
      vector<int> row(q.size());
      transform(q.begin(), q.end(), row.begin(), [](TreeNode const* a) { return a->val; });
      res.push_back(row);
      for (int i = 0, j = q.size(); i < j; ++i) {
        auto t = q.front();
        if (t->left) q.push_back(t->left);
        if (t->right) q.push_back(t->right);
        q.pop_front();
      }
    }
    return res;
  }
};
