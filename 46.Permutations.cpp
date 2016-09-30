class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    do {
      res.push_back(vector<int> (nums));
    } while (next_permutation(nums.begin(), nums.end()));
    return res;
  }
};
