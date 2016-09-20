int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0) return 1;
    for (int i = 0; i < numsSize; ++i) {
        while(nums[i] > 0 && nums[i] <= numsSize && nums[nums[i]-1] != nums[i]) { 
            int tmp1 = nums[nums[i]-1];
            int tmp2 = nums[i];
            nums[nums[i]-1] = tmp2;
            nums[i] = tmp1;
        }
        
    }
    for (int i = 0; i < numsSize; ++i) {
        if (i+1 != nums[i]) return i+1;
    }
    return numsSize+1;
}

//0ms 18%
