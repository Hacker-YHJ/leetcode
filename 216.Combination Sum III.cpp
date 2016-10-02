class Solution {
  vector<vector<int> > res;
  vector<int> curr;
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    helper(k, n, 9);
    return res;
  }

  void helper(int k,int n, int m) {
    if (k == 0) {
      if (n == 0) res.push_back(curr);
      return;
    }
    if (m < 1) return;
    helper(k, n, m - 1);
    curr.push_back(m);
    helper(k - 1, n - m, m - 1);
    curr.pop_back();
  }
};
