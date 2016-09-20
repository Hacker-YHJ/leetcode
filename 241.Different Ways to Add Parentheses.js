/**
 * @param {string} input
 * @return {number[]}
 */
var diffWaysToCompute = function(input) {
    var result = [];
    var o1, o2;
    if (!Number.isNaN(+input)) return [+input];
    for (var i = 0; i < input.length; ++i) {
        if ('-' === input[i]) {
            o1 = diffWaysToCompute(input.slice(0, i))
            o2 = diffWaysToCompute(input.slice(i+1));
            o1.forEach( function (e) {
                o2.forEach( function (v) {
                    result.push(e-v);
                });
            });
        }
        else if ('+' === input[i]) {
            o1 = diffWaysToCompute(input.slice(0, i))
            o2 = diffWaysToCompute(input.slice(i+1));
            o1.forEach( function (e) {
                o2.forEach( function (v) {
                    result.push(e+v);
                });
            });
        }
        else if ('*' === input[i]) {
            o1 = diffWaysToCompute(input.slice(0, i))
            o2 = diffWaysToCompute(input.slice(i+1));
            o1.forEach( function (e) {
                o2.forEach( function (v) {
                    result.push(e*v);
                });
            });
        }
    }
    return result;
};
