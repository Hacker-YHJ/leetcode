class Solution {
public:
  int lastRemaining(int n) {
    return helper(n, true);
  }

  int helper(int n, bool left) {
    if (n == 1) return n;
    if (n % 2) {
      return helper(n / 2, !left) * 2;
    } else if (left) {
      return helper(n / 2,  !left) * 2;
    } else {
      return helper(n / 2, !left) * 2 - 1;
    }
  }
};
