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
  typedef vector<int> VI;
  typedef vector<int>::iterator VII;
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    auto p = preorder.begin();
    return helper(preorder, inorder, p, inorder.begin(), inorder.end());
  }
  TreeNode* helper(VI& pre, VI& in, VII& pI, VII iIB, VII iIE) {
    if (iIB == iIE) return nullptr;
    TreeNode* r = new TreeNode(*pI);

    auto p = iIB;
    while (*p != *pI) ++p;
    r->left = helper(pre, in, ++pI, iIB, p);
    r->right = helper(pre, in, pI, p + 1, iIE);

    return r;
  }
};
