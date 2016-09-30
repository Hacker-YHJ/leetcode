/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
  let arr = preorder.split(',');
  let stack = [];
  let cStack = [];
  let count = 0;
  let emptyFlag = false;
  for (let i = 0, j = arr.length; i < j; ++i) {
    if (emptyFlag) return false;
    if (arr[i] === '#') {
      while (cStack.length !== 0 && --cStack[cStack.length - 1] === 0) {
        cStack.pop();
        stack.pop();
      }
      emptyFlag = stack.length === 0;
    } else {
      stack.push(arr[i]);
      cStack.push(2);
    }
  }
  return stack.length === 0;
};
