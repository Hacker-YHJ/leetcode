class Solution {
public:
  int longestPalindrome(string s) {
    bool m[256];
    int res = 0;
    for (int i = 0; i < 256; ++i) {
      m[i] = false;
    }
    for (unsigned char c : s) {
      if (m[c]) res += 2;
      m[c] = !m[c];
    }
    for (int i = 0; i < 256; ++i) {
      if (m[i]) return res + 1;
    }
    return res;
  }
};
