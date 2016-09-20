class Solution {
public:
  int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    long res = 1;
    a = a % 1337;
    int t = b.back();
    b.pop_back();
    res *= helper(a, t);
    res %= 1337;
    res *= helper(superPow(a, b), 10);
    return res % 1337;
  }

  int helper(double a, int b) {
    long res;
    if (b < 6) {
      res = pow(a, b);
    }
    else {
      res = ((long)pow(a, 5)) % 1337;
      res *= ((long)pow(a, b - 5)) % 1337;
    }
    return res % 1337;
  }
};
