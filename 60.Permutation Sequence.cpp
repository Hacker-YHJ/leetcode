class Solution {
public:
  string getPermutation(int n, int k) {
    string ans, builder;
    int f[n + 1];
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
      f[i] = f[i-1] * i;
      builder += '0' + i;
    }
    --k;
    int idx = n;
    while (idx) {
      int i = k / f[idx-1];
      k -= i * f[idx-1];
      ans += builder[i];
      builder.erase(i, 1);
      idx--;
    }
    return ans;
  }
};
