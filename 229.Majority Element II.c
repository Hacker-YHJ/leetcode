/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int c1 = 0, c2 = 0;
    int p1 = 0, p2 = 0;
    int t1, t2;
    int *toR;
    
    for (int i = 0; i < numsSize; ++i) {
        if (0 == c1) t1 = (c1 = 1, nums[i]); 
        else if (t1 == nums[i]) ++c1;
        else if (0 == c2) t2 = (c2 = 1, nums[i]);
        else if (t2 == nums[i]) ++c2;
        else --c1, --c2;
    }
    for (int i = 0; i < numsSize; ++i) {
        if (t1 == nums[i]) ++p1;
        else if (t2 == nums[i]) ++p2;
    }
    if (p1 > numsSize/3 && p2 > numsSize/3) {
        *returnSize = 2;
        toR = (int*)malloc(*returnSize*sizeof(int));
        toR[0] = (toR[1] = t2, t1);
    }
    else if (p1 > numsSize/3 || p2 > numsSize/3) {
        *returnSize = 1;
        toR = (int*)malloc(*returnSize*sizeof(int));
        toR[0] = p1 > numsSize/3 ? t1 : t2;
    }
    else {
        *returnSize = 0;
        toR = (int*)malloc(0);
    }
    return toR;
}

// 8ms
// 32%
