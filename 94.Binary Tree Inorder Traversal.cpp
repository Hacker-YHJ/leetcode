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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> v;
        vector<int> res;
        pushSelfAndLeft(v, root);
        while (!v.empty()) {
            TreeNode* r = v.top();
            res.push_back(r->val);
            v.pop();
            pushSelfAndLeft(v, r->right);
        }
        return res;
    }
    void pushSelfAndLeft(stack<TreeNode*> &s, TreeNode* t) {
        while (t != NULL) {
            s.push(t);
            t = t->left;
        }
        return;
    }
};

// 0 ms 14%
