class Solution {
public:
  char findTheDifference(string s, string t) {
    int chars[26];
    for (int i = 0; i < 26; ++i) {
      chars[i] = 0;
    }
    for (int i = 0, j = s.size(); i < j; ++i) {
      chars[s[i] - 'a']++;
      chars[t[i] - 'a']--;
    }
    chars[t[t.size()-1]-'a']--;
    for (int i = 0; i < 26; ++i) {
      if (chars[i] == -1) return (char)(i + 'a');
    }
    return '\0';
  }
};
