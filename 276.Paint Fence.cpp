class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0) return 0;
    if (n == 1) return k;
    int a = k,
      b = k * (k - 1);
    for (int i = 2; i < n; ++i) {
      int c = (b + a) * (k-1);
      a = b;
      b = c;
    }
    return a + b;
  }
};
