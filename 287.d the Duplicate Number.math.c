int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

// 4ms 66%
