/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *cur = root;
        TreeLinkNode *tmp = NULL;
        TreeLinkNode *lm = NULL;
        while(cur) {
            tmp = NULL;
            lm = NULL;
            while(cur) {
                if (cur->left) {
                    if (tmp) tmp->next = cur->left;
                    else lm = cur->left;
                    tmp = cur->left;
                }
                if (cur->right) {
                    if (tmp) tmp->next = cur->right;
                    else lm = cur->right;
                    tmp = cur->right;
                }
                do {
                    cur = cur->next;
                } while (cur && !cur->left && !cur->right);
            }
            cur = lm;
        }
    }
};

// 40ms 17%
