int find(int* arr, int target, int s, int e) {
    if (s == e) return s;
    int mid = (e-s)/2+s;
    if (arr[mid] > target) return find(arr, target, s, mid);
    if (arr[mid] < target) return find(arr, target, mid+1, e);
    return mid;
} 

int lengthOfLIS(int* nums, int numsSize) {
    if (0 == numsSize) return 0;
    
    int tails[numsSize];
    int tailsIndex = 0;
    tails[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        int t = find(tails, nums[i], 0, tailsIndex);
        if (tails[t] < nums[i]) tails[++tailsIndex] = nums[i];
        else {
         tails[t] = nums[i];   
        }
        // for (int k = 0; k <= tailsIndex; ++k) printf("%d ", tails[k]);
        // printf("\n");
    }
    return tailsIndex+1;
}

// 0ms %73
