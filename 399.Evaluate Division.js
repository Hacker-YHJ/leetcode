/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
    let len = equations.length;
    let qLen = queries.length;
    s = {};
    res = [];
    for (let i = 0; i < len; ++i) {
        insert(s, equations[i], values[i]);
    }
    for (let i = 0; i < qLen; ++i) {
        if (s[queries[i][0]] === undefined || s[queries[i][1]] === undefined) {
            res[i] = -1.0;
        } else if (s[queries[i][0]] != s[queries[i][1]]) {
            res[i] = -1.0;
        } else {
            res[i] = s[queries[i][0]][queries[i][0]] / s[queries[i][1]][queries[i][1]];
        }
    }
    return res;
};

var insert = function(s, p, v) {
    let firstIn = s[p[0]] !== undefined;
    let secondIn = s[p[1]] !== undefined;
    if (!firstIn && !secondIn) {
        tmp = {}
        tmp[p[1]] = 1;
        tmp[p[0]] = v;
        s[p[0]] = tmp;
        s[p[1]] = tmp;
    } else if (!firstIn) {
        s[p[0]] = s[p[1]];
        s[p[0]][p[0]] = v * s[p[1]][p[1]];
    } else if (!secondIn) {
        s[p[1]] = s[p[0]];
        s[p[1]][p[1]] = s[p[0]][p[0]] / v;
    } else if (s[p[0]] !== s[p[1]]) {
        let multiplier = s[p[1]][p[1]] * v;
        let ref = s[p[0]];
        for (let k in ref) {
            s[k] = s[p[1]];
            s[k][k] = ref[k] * multiplier;
        }
    }
};
