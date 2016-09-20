/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getDepth(struct TreeNode* root) {
    if (NULL == root) return 0;
    else {
        int dl = getDepth(root->left), dr = getDepth(root->right);
        return dl > dr ? dl + 1 : dr + 1;
    }
}

void calc(struct TreeNode* p, int counter, int depth, int* result, int* index) {
    if (NULL == p) return;
    if (counter > index[depth]) {
        index[depth] = counter;
        result[depth] = p->val;
    }
    calc(p->right, counter*2+1, depth+1, result, index);
    calc(p->left, counter*2, depth+1, result, index);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int depth = getDepth(root);
    *returnSize = depth;
    int* result = (int*)malloc(sizeof(int)*depth);
    int* index = (int*)malloc(sizeof(int)*depth);
    memset(result,0,sizeof(int)*depth);
    memset(index,0,sizeof(int)*depth);
    calc(root, 1, 0, result, index);
    return result;
}

// 12ms
