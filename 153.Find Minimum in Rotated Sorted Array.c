int findMin(int* nums, int numsSize) {
    int start = 0, end = numsSize-1, mid = numsSize/2;
    if (nums[start] <= nums[mid] && nums[mid] <= nums[end]) return nums[start];
    while (start < end-1) {
        if (nums[mid] < nums[start]) {
            end = mid;
            mid = (end-start)/2+start;
        }
        else {
            start = mid;
            mid = (end-start)/2+start;
        }
    }
    return nums[end] > nums[start] ? nums[start] : nums[end];
}

// 0ms 12%
