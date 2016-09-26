class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (const auto& n : nums) { m[n]++; }
    vector<pair<int, int> > res(m.begin(), m.end());
    sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });
    vector<int> ans(k);
    transform(res.begin(), res.begin() + k, ans.begin(), [](pair<int, int>& a) { return a.first; });
    return ans;
  }
};
