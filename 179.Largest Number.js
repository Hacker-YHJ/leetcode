/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    if (nums.length === 0) return '';
    nums.sort(function (n, m) {
      var ln = n !== 0 ? Math.log10(n) + 1 | 0 : 1,
          lm = n !== 0 ? Math.log10(m) + 1 | 0 : 1;
      
      return (m*Math.pow(10, ln)+n) - (n*Math.pow(10, lm)+m);
    });
    if (nums[0] === 0) return '0';
    return nums.join('')
};

// 204ms 20%
