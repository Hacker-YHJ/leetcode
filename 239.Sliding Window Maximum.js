/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    if (0 === nums.length || 0 === k) return [];
    var queue = [];
    var result = [];
    for (var i = 0; i < nums.length; ++i) {
        if (i-k === queue[0]) queue.shift();
        var t = queue[queue.length-1];
        while (t !== undefined && nums[t] < nums[i]) {
            queue.pop();
            t = queue[queue.length-1];
        }
        queue.push(i);
        if (i >= k-1) result.push(nums[queue[0]]);
    }
    return result;
};

