void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int p = 0, n = 0;
    int m = 0x80000000;
    for (int i = 0; i <= numsSize; ++i) {
        if (0 == nums[i] || i == numsSize) {
            p = n = 0;
            continue;
        }
        int tp, tn;
        tp = 0 == p ? nums[i] : p * nums[i];
        tn = 0 == n ? 0 : n * nums[i];
        if (nums[i] < 0) swap(&tp, &tn);
        p = tp;
        n = tn;
        m = m > n ? m : n;
        m = m > p ? m : p;
    }
    return m;
}

// 4ms
// 1%
