class Solution {
private:
  vector<int> c;
  vector<vector<int> > res;
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    c = candidates;
    vector<int> curr;
    helper(0, target, curr);
    return res;
  }

  void helper(int idx, int tar, vector<int>& curr) {
    if (tar == 0) {
      res.push_back(curr);
      return;
    }
    for(int i = idx; i < c.size() && tar >= c[i]; i++) {
      if(i != idx && c[i] == c[i-1])
        continue;
      curr.push_back(c[i]);
      helper(i + 1, tar - c[i], curr);
      curr.pop_back();
    }
  }
};
