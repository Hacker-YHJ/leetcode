/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function (root) {
    update(root);
    return root.max;
};

var update = function (root) {
    var t = root;
    if (t === null) return;
    update(t.left);
    update(t.right);
    if (t.left === null && t.right === null) {
        t.singleMax = t.val;
        t.doubleMax = t.val;
        t.max = t.val;
    } else if (t.left === null) {
        t.singleMax = t.val + t.right.singleMax > t.val ? t.val + t.right.singleMax : t.val;
        t.doubleMax = t.val + t.right.singleMax > t.val ? t.val + t.right.singleMax : t.val;
        t.max = t.doubleMax > t.right.max ? t.doubleMax : t.right.max;
    } else if (t.right === null) {
        t.singleMax = t.val + t.left.singleMax > t.val ? t.val + t.left.singleMax : t.val;
        t.doubleMax = t.val + t.left.singleMax > t.val ? t.val + t.left.singleMax : t.val;
        t.max = t.doubleMax > t.left.max ? t.doubleMax : t.left.max;
    } else {
        t.doubleMax = t.val + (t.left.singleMax > 0 ? t.left.singleMax : 0) + (t.right.singleMax > 0 ? t.right.singleMax : 0);
        tmp = t.left.singleMax > t.right.singleMax ? t.left.singleMax : t.right.singleMax;
        t.singleMax = t.val + (tmp > 0 ? tmp : 0);
        t.max = t.doubleMax > t.left.max ? t.doubleMax : t.left.max;
        t.max = t.max > t.right.max ? t.max : t.right.max;
    }
}
