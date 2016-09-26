class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    multiset<pair<int, pair<vector<vector<int> >::iterator, vector<int>::iterator> > > m;
    for (auto p = matrix.begin(); p != matrix.end(); ++p) {
      m.insert(make_pair((*p)[0], make_pair(p, p->begin())));
    }
    int res;
    while (k--) {
      auto top = *m.begin();
      m.erase(m.begin());
      res = top.first;
      auto t = top.second.second + 1;
      if (t != top.second.first->end()) {
        m.insert(make_pair(*t, make_pair(top.second.first, t)));
      }
    }
    return res;
  }
};
