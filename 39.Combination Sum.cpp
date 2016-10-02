class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return helper(candidates, target, {});
  }

  vector<vector<int> > helper(vector<int> c, int tar, vector<int> curr) {
    if (tar == 0) return {curr};
    if (c.empty()) return {};
    auto p = c.back();
    vector<vector<int> > res;
    c.pop_back();
    while (tar >= 0) {
      auto response = helper(c, tar, curr);
      tar -= p;
      curr.push_back(p);
      res.reserve(res.size() + response.size());
      res.insert(res.end(), response.begin(), response.end());
    }
    return res;
  }
};
