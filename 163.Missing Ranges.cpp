class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, long lower, long upper) {
    vector<string> res;
    for (auto const& n : nums) {
      if (lower < n) {
        res.push_back(lower < n-1 ? (to_string(lower) + "->" + to_string(n-1)) : to_string(lower));
      }
      lower = (long) n+1;
    }
    if (lower < upper) {
      res.push_back(to_string(lower) + "->" + to_string(upper));
    } else if (lower == upper) {
      res.push_back(to_string(lower));
    }
    return res;
  }
};
