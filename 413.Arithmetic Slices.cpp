class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    auto s = A.begin(), e = s;
    int sum = 0;
    while (e != A.end() && e + 1 != A.end()) {
      int diff = *++e - *s;
      while (e != A.end() && *(e) - *(e - 1) == diff) e++;
      if (e - s > 2) {
        sum += (e - s - 1) * (e - s - 2) / 2;
      }
      s = --e;
    }
    return sum;
  }
};
