/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Result {
public:
    bool b;
    int upper;
    int lower;
    Result() {}
    Result(bool b, int upper, int lower) : b(b), upper(upper), lower(lower) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root).b;
    }
    Result validate(TreeNode* t) {
        if (!t) return Result(true, 0, 0);
        if (!t->left && !t->right) return Result(true, t->val, t->val);
        Result lr, ll;
        if (!t->left) {
            lr = validate(t->right);
            return Result(lr.b && t->val < lr.lower, lr.upper, t->val);
        }
        if (!t->right) {
            ll = validate(t->left);
            return Result(ll.b && t->val > ll.upper, t->val, ll.lower);
        }
        lr = validate(t->right);
        ll = validate(t->left);
        return Result(ll.b && lr.b && t->val < lr.lower && t->val > ll.upper, lr.upper, ll.lower);
    }
};
//12ms 66%
