struct pair_hash {
  inline size_t operator()(const pair<int,int> & v) const {
    return v.first*31+v.second;
  }
};

class Solution {
public:
  bool isReflected(vector<pair<int, int>>& points) {
    int minX = numeric_limits<int>::max(),
      maxX = numeric_limits<int>::min();
    for (auto const& p : points) {
      minX = min(minX, p.first);
      maxX = max(maxX, p.first);
    }
    int mid2 = minX + maxX;

    unordered_set<pair<int, int>, pair_hash> s(points.begin(), points.end());
    for (auto const& p : points) {
      if (s.find(make_pair(mid2 - p.first, p.second)) == s.end()) return false;
    }
    return true;
  }
};
