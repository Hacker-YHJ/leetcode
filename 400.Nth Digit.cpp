class Solution {
public:
  int findNthDigit(int n) {
    int d = 1;
    long num = 1;
    while (n > 9 * d * num) {
      n -= 9 * d * num;
      d++;
      num *= 10;
    }
    long resN = (n - 1) / d + num;
    int idx = (n - 1) % d;
    return (resN / (int)pow(10, (d - idx - 1))) % 10;
  }
};
