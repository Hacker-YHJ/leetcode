/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    "use strict";
    if (n === 0) return [];
    if (n === 1) return [0];
    
    var nodes = [];
    var result = [];
    var tmp = [];
    // construct tree
    for (let i = 0; i < n; ++i) {
      nodes[i] = new Set();
    }
    // trace all edges
    edges.forEach(function (edge) {
      nodes[edge[0]].add(edge[1]);
      nodes[edge[1]].add(edge[0]);
    });

    // get all 1 degree node
    nodes.forEach(function (node, i) {
      if (node.size === 1) {
        tmp.push(i);
      }
    });

    // everytime remove all one degree node, then refresh
    while (tmp.length !== 0) {
      let len = tmp.length;
      result = [];
      for (let i = 0; i < len; ++i) {
        let nodeIndex = tmp.shift();
        result.push(nodeIndex);
        nodes[nodeIndex].forEach(function (i) {
          nodes[i].delete(nodeIndex);
          if (nodes[i].size === 1) {
            tmp.push(i);
          }
        });
      }
    }
    return result;
};

// 292ms 52%
