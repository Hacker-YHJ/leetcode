void sortColors(int* nums, int numsSize) {
    int s = 0, e = numsSize-1;
    for (int i = 0; i < numsSize; ++i) {
        while (2 == nums[i] && e >= i) nums[i] = nums[e], nums[e--] = 2;
        while (0 == nums[i] && s < i) nums[i] = nums[s], nums[s++] = 0;
    }
}

//0ms 6%
