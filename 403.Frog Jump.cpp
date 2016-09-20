auto comp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
  if (a.first != b.first) return a.first < b.first;
  else return a.second < b.second;
};
class Solution {
public:
  bool canCross(vector<int>& stones) {
    if (stones.empty()) return false;
    set<pair<int, int>, decltype(comp)> q(comp);
    unordered_set<int> s(stones.begin(), stones.end());
    int m = stones.back();

    q.insert(make_pair(*stones.begin(), 0));
    while (!q.empty()) {
      auto first = q.begin()->first;
      auto second = q.begin()->second;
      q.erase(q.begin());
      for (int i = second - 1; i <= second + 1; ++i) {
        if (i <= 0) continue;
        int nxt = i + first;
        if (nxt <= m && s.find(nxt) != s.end()) {
          if (nxt == m) return true;
          q.insert(make_pair(nxt, i));
        }
      }
    }
    return false;
  }
};
