/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    s = s.trim();
    p = s.split('e');
    if (p.length === 2) {
        return isFloat(p[0]) && isInt(p[1]);
    }
    else if (p.length === 1) {
        return isFloat(p[0]);
    }
    return false;
};

var isFloat = function(s) {
    let check = true;
    let firstDot = false;
    let i = 0;
    if (s[i] == '-' || s[i] == '+') {
        i = 1;
    }
    for (let j = s.length; i < j; ++i) {
        if ((s[i] < '0' || s[i] > '9') && s[i] !== '.') {
            check = false;
            break;
        }
        else if (s[i] === '.') {
            if (firstDot) {
                check = false;
                break;
            }
            else {
                firstDot = true;
            }
        }
    }
    return check && isFinite(parseFloat(s));
}

var isInt = function(s) {
    let check = true;
    let i = 0;
    if (s[i] == '-' || s[i] == '+') {
        i = 1;
    }
    for (let j = s.length; i < j; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            check = false;
            break;
        }
    }
    return check && isFinite(parseInt(s)) && (parseInt(s) === parseFloat(s));
}
