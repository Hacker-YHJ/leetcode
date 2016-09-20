class Solution {
public:
  int maxRotateFunction(vector<int>& A) {
    int r = 0;
    int s = A.size();
    long sum = accumulate(A.begin(), A.end(), (long)0);
    long init = accumulate(A.begin(), A.end(), (long)0, [&](long a, long b) {
        return a + b * (r++);
      });
    long res = accumulate(A.rbegin(), A.rend(), init, [&](long a, long b) {
        init = init + sum - s * b;
        return a > init ? a : init;
      });
    return res;
  }
};
