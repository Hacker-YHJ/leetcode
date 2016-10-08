class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (isNotLetter(s[i]) && i < j) i++;
      while (isNotLetter(s[j]) && i < j) j--;
      if (i == j) return true;
      if (s[i] == s[j] || (s[i] >= 'A' && s[i] - s[j] == 'A' - 'a') || (s[j] >= 'A' && s[i] - s[j] == 'a' - 'A')) {
        ++i;
        --j;
        continue;
      }
      return false;
    }
    return true;
  }

  bool isNotLetter(char c) {
    return (c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9');
  }
};
