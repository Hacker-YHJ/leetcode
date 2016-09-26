typedef pair<int, int> pInt;
typedef unordered_map<int, int> pMap;
typedef vector<pInt > pVec;
typedef vector<pInt >::iterator pVecItr;
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    pMap m;
    for (const auto& n : nums) { m[n]++; }
    pVec res(m.begin(), m.end());
    helper(res.begin(), res.end(), k);
    vector<int> ans(k);
    transform(res.begin(), res.begin() + k, ans.begin(), [](pInt& a) { return a.first; });
    return ans;
  }
  void helper(const pVecItr s, const pVecItr e, int k) {
    auto last = e - 1;
    auto j = s;
    for (auto i = s; i < e; ++i) {
      if (i->second > last->second) {
        swap(*i, *j);
        ++j;
      }
    }
    swap(*j, *last);
    if (distance(s, j) > k) {
      helper(s, j, k);
    } else if (distance(s, j) < k - 1 ) {
      helper(j + 1 , e, k - distance(s, j) - 1);
    }
  }
};
