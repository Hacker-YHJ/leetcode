class Solution {
private:
  unordered_map<int, int> m;
public:
  int integerReplacement(long n) {
    if (m.find(n) != m.end()) return m[n];
    int on = n;
    int res = 0;
    while (!(n % 2)) {
      n >>= 1;
      ++res;
    }
    if (n == 1) {
      m.insert({on, res});
      return res;
    } else {
      int ans = 1 + res + min(integerReplacement(n - 1), integerReplacement(n + 1));
      m.insert({on, ans});
      return ans;
    }
  }
};
