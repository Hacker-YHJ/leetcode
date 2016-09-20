class Solution {
public:
  int numDecodings(string s) {
    int sLen = s.size();
    if (sLen < 1) return 0;
    int a = 1;
    int b = s[0] >= '1' && s[0] <= '9' ? 1 : 0;
    bool flag = true;
    for (int i = 1; i < sLen; ++i) {
      int r = s[i] >= '1' && s[i] <= '9' ? b : 0;
      int num = (s[i-1] - '0') * 10 + (s[i] - '0');
      if (num >= 10 && num <= 26) r += a;
      else if (num % 10 == 0) {
        flag = false;
        break;
      }
      a = b;
      b = r;
    }
    return flag ? b : 0;
  }
};
