/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode* stack[1000];
    int index;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct TreeNode *p = root;
    struct BSTIterator *iter = (struct BSTIterator*)malloc(sizeof(struct BSTIterator));
    iter->index = 0;
    while (p) {
        iter->stack[iter->index++] = p;
        p = p->left;
    }
    return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return iter->index;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    struct TreeNode* p = iter->stack[--iter->index];
    int value = p->val;
    p = p->right;
    while (p) {
        iter->stack[iter->index++] = p;
        p = p->left;
    }
    return value;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */

