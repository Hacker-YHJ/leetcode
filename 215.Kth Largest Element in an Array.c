int findKthLargest(int* nums, int numsSize, int k) {
    int p = -1;
    int s = 0, e = numsSize - 1;
    for(;p != k-1;) {
        int i = s, ii = s;
        if (s == e) return nums[s];
        while (ii < e) {
            if (nums[ii] > nums[e]) {
                if (ii != i) {
                    nums[ii] ^= nums[i];
                    nums[i] ^= nums[ii];
                    nums[ii] ^= nums[i];
                }
                ++i;
            }
            ++ii;
        }
        if (e != i) {
            nums[e] ^= nums[i];
            nums[i] ^= nums[e];
            nums[e] ^= nums[i];
        }
        p = i;
        //printf("%d %d %d\n", s, e, p);
        if (p < k-1) s = p+1;
        else e = p-1;
    }
    return nums[p];
}

// 0ms 33%
