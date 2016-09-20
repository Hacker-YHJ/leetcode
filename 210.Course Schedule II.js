/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function(numCourses, prerequisites) {
    'use strict';
    var graph = {};
    var nonPointed = [];
    var result = [];
    
    for (let i = 0; i < numCourses; ++i) {
        graph[i] = {val: i, pre: 0, to: []};
    }
    prerequisites.forEach(function (e, i) {
        ++graph[e[0]].pre;
        graph[e[1]].to.push(graph[e[0]]);
    })
    for (let i = 0; i < numCourses; ++i) {
        if (graph[i].pre === 0) nonPointed.push(graph[i]);
    }
    while (nonPointed.length) {
        let s = nonPointed.pop();
        result.push(s.val);
        for (let i = 0; i < s.to.length; ++i) {
            --s.to[i].pre;
            if (s.to[i].pre === 0) nonPointed.unshift(s.to[i]);
        }
    }
    return result.length === numCourses? result : [];
};
