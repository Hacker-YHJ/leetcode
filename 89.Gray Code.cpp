class Solution {
public:
  vector<int> grayCode(int n) {
    int num = 1 << n;
    int x[num];
    x[0] = 0;
    int t = 1;
    int e = 0;
    for (int i = 1; i < num;) {
      if (e == 0) {
        for (; e < t; ++e, ++i) {
          x[i] = x[e] + t;
        }
      } else {
        for (e = t - 1; e >= 0; --e, ++i) {
          x[i] = x[e] + t;
        }
      }
      t <<= 1;
    }
    return vector<int> (x, x + sizeof x / sizeof x[0]);
  }
};
