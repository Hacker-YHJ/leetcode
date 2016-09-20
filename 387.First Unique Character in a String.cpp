class Solution {
public:
  int firstUniqChar(string s) {
    int m[26];
    int len = s.size();
    int first = 0x7FFFFFFF;
    for (int i = 0; i < 26; ++i) {
      m[i] = -1;
    }
    for (int i = 0; i < len; ++i) {
      int idx = s[i] - 'a';
      if (m[idx] == -1) m[idx] = i;
      else m[idx] = -2;
    }
    for (int i = 0; i < 26; ++i) {
      if (m[i] >= 0) first = first < m[i] ? first : m[i];
    }
    return first == 0x7FFFFFFF ? -1 : first;
  }
};
