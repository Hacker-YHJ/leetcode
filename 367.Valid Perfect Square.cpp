class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int s = 1;
    int e = num;
    long t = e / 2;
    do {
      if (t * t == num) return true;
      else if (t * t > num) {
        e = t - 1;
        t = (s + e) / 2;
      }
      else {
        s = t + 1;
        t = (s + e) / 2;
      }
    } while (s <= e);
    return false;
  }
};
