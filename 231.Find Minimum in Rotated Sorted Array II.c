int findMin(int* nums, int numsSize) {
    int start = 0, end = numsSize-1, mid = numsSize/2;
    while (start < end-1) {
        if (nums[start] < nums[mid] && nums[mid] < nums[end]) return nums[start];
        if (nums[mid] < nums[start] || nums[mid] == nums[start] && nums[mid] < nums[end] || nums[mid] == nums[end] && nums[mid] > nums[start]) {
            end = mid;
            mid = (end-start)/2+start;
        }
        else if (nums[mid] > nums[end]) {
            start = mid;
            mid = (end-start)/2+start;
        }
        else if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
            ++start;
            --end;
        }
    }
    return nums[end] > nums[start] ? nums[start] : nums[end];
}

//4ms 14%
