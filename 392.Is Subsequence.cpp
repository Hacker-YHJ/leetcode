class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sLen = s.size();
    int tLen = t.size();
    int i = tLen - 1;
    int j = sLen - 1;
    if (j < 0) return true;
    while (i >= 0) {
      if (s[j] == t[i]) --j;
      if (j < 0) return true;
      --i;
    }
    return false;
  }
};
