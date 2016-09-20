/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
  let inputs = input.split('\n');
  let lens = [];
  let maxLength = 0;
  for (let i in inputs) {
    let tmp = inputs[i].split('\t');
    let indent = tmp.length-1;
    let value = tmp[tmp.length-1];
    let isFile = value.indexOf('.') > 0;
    lens[indent] = value.length;
    if (isFile) {
      let testMax = indent;
      for (let j = 0; j <= indent; ++j) {
        testMax += lens[j];
      }
      maxLength = maxLength > testMax ? maxLength : testMax;
    }
  }
  return maxLength;
};
