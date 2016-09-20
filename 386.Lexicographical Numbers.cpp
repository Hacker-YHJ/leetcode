class Solution {
private:
  vector<int> res;
  int m;
public:
  vector<int> lexicalOrder(int n) {
    m = n;
    helper(1);
    return res;
  }

  void helper(int n) {
    res.push_back(n);
    if (n * 10 <= m) helper(n * 10);
    if (n + 1 <= m && (n + 1) % 10 != 0) helper(n + 1);
  }
};
