/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode* r, int* k, int* result) {
    if (r->left) helper(r->left, k, result);
    --*k;
    if (!*k) {
        *result = r->val;
        return;
    }
    if (k && r->right) helper(r->right, k, result);
}
int kthSmallest(struct TreeNode* root, int k) {
    int result = 0, pos = k;
    helper(root, &k, &result);
    return result;
}

// 12ms 21%
