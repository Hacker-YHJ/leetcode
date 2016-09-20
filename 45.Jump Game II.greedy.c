int jump(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    int step_count = 0;
    int last_jump_max = 0;
    int current_jump_max = 0;
    for(int i=0; i<numsSize-1; i++) {
        current_jump_max = current_jump_max > i+nums[i] ? current_jump_max : i+nums[i];
        if( i == last_jump_max ) {
            step_count++;
            last_jump_max = current_jump_max;
        } 
    }
    return step_count;
}

// 8ms 21.6%
