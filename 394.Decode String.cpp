class Solution {
public:
  string decodeString(string s) {
    string res;
    int len = s.size();
    int times = 0;
    int i = 0;
    while (i < len) {
      if ((s[i] < '0' || s[i] > '9') && s[i] != '[' && s[i] != ']') {
        res += s[i++];
      }
      else if (s[i] >= '0' && s[i] <= '9') {
        times = 10 * times + s[i] - '0';
        ++i;
      }
      else {
        int m = i + 1;
        int n = m;
        int p = 1;
        while (p) {
          if (s[n] == ']') --p;
          else if (s[n] == '[') ++p;
          ++n;
        }
        string sub = decodeString(s.substr(m, n - m - 1));
        while (times--) res += sub;
        i = n;
        times = 0;
      }
    }
    return res;
  }
};
