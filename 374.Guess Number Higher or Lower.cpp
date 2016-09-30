// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int s = 0, e = n;
    int mid = s + (e - s) / 2;
    int tmp;
    while ((tmp = guess(mid)) != 0) {
      if (tmp == 1) {
        s = mid + 1;
      } else {
        e = mid;
      }
      mid = s + (e - s) / 2;
    }
    return mid;
  }
};
