/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
  var arr = s.split(' ');
  return arr.reduce(function(p, a) {
      return a.length === 0 ? p : a.length;
    }, 0);
};
