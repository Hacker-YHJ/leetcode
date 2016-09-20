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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if (root) s.push(root);
        
        while (!s.empty()) {
            TreeNode* t = s.top();
            res.push_back(t->val);
            s.pop();
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
        return res;
    }
};

// 0ms 12%
