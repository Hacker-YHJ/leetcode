/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  var ans = (x < 0 ? -1 : 1) * parseInt(Math.abs(x).toString().split('').reverse().join(''));
  return (ans > 2147483647 || ans < -2147483648) ? 0 : ans;
};
