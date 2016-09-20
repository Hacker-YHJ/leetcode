/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int m1[numsSize];
    int m2[numsSize];
    int* result = (int*)malloc(sizeof(int)*numsSize);
    m1[0] = m2[numsSize-1] = 1;

    for (int i = 1; i < numsSize; ++i) {
        m1[i] = nums[i-1]*m1[i-1];
        m2[numsSize-i-1] = nums[numsSize-i]*m2[numsSize-i];
    }
    for (int i = 0; i < numsSize; ++i) {
        result[i] = m1[i] * m2[i];
    }
    return result;
}

// 36ms
