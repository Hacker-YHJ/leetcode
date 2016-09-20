int missingNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; ++i) {
        result ^= nums[i];
        result ^= i;
    }
    return result ^ numsSize;
}

//16ms 10%
