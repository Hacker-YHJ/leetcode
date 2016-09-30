class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> res(num+1, 0);
    for (int i = 1; i <= num; i <<= 1) {
      for (int j = 0; j < i; ++j) {
        if (i + j <= num) res[i+j] = res[j] + 1;
      }
    }
    return res;
  }
};
