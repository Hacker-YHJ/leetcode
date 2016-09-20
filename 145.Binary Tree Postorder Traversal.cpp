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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* last = NULL;
        pushSelfAndLeft(s, root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            if (p -> right && last != p -> right)
                pushSelfAndLeft(s, p -> right);
            else {
                res.push_back(p -> val);
                last = p;
                s.pop();
            }
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

// 0ms 14%
