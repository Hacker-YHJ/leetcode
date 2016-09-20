/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (NULL == root) return 0;
    
    struct TreeNode* p = root;
    struct TreeNode* n = root;
    int leftCount = 0;
    int rightCount = 0;
    int result = 0;
    int extra = 0;
    // if full
    while (NULL != p) p = p->left,++leftCount;
    p = root;
    while (NULL != p) p = p->right,++rightCount;
    if (leftCount == rightCount) return (int)pow(2,leftCount)-1;
    // not full, find how many extras at bottom
    result = (int)pow(2, rightCount)-1;
    
    p = root;
    while (NULL != p) {
        rightCount = 0;
        --leftCount;
        n = p->left;
        while (NULL != n) n = n->right, ++rightCount;
        if (rightCount == leftCount) p = p->right,extra = (extra << 1) | 0x1;
        else p = p->left, extra = extra << 1;
    }
    printf("%d\n", extra);
    return result + extra;
}

//104 ms, 75%
