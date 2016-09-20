#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Node {
public:
  string v;
  vector<vector<string> > ans;
  unordered_set<Node*> links;
  int dis;
  Node(string word): v(word), dis(0x7FFFFFFF){}
};

class Solution {
public:
  Node* s;
  Node* e;
  unordered_set<Node*> g;
  queue<Node*> todo;

  vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    init(beginWord, endWord, wordList);
    if (s->links.empty() || e->links.empty()) return vector<vector<string> >();

    todo.push(s);
    int searchDepth = 1;
    while (!todo.empty()) {
      queue<Node*> tmpQ;
      while (!todo.empty()) {
        auto t = todo.front();
        todo.pop();
        for (auto &p : t->links) {
          if (p->dis >= searchDepth) {
            if (p->dis > searchDepth) {
              tmpQ.push(p);
            }
            p->dis = searchDepth;
            auto tmp = t->ans;
            for (auto &tmpAns : tmp) {
              tmpAns.push_back(p->v);
            }
            p->ans.reserve(p->ans.size() + tmp.size());
            p->ans.insert(p->ans.end(), tmp.begin(), tmp.end());
          }
        }
      }
      todo = tmpQ;
      ++searchDepth;
    }
    return e->ans;
  }

  void init(string beginWord, string endWord, unordered_set<string> &wordList) {
    s = new Node(beginWord);
    e = new Node(endWord);
    s->dis = 0;
    vector<string> tmp;
    tmp.push_back(s->v);
    s->ans.push_back(tmp);

    g.insert(s);
    g.insert(e);
    for (auto w : wordList) {
      if (w != s->v && w != e->v) {
        g.insert(new Node(w));
      }
    }

    for (auto p : g) {
      for (auto q : g) {
        if (p == q) continue;
        if (isConnected(p->v, q->v)) {
          p->links.insert(q);
        }
      }
    }
  }

  bool isConnected(string s, string t) {
      int sLen = s.size();
      bool dif = false;
      if (sLen != t.size()) return false;
      for (int i = 0; i < sLen; ++i) {
          if (s[i] != t[i]) {
              if (dif) return false;
              dif = true;
          }
      }
      return true;
  }
};
