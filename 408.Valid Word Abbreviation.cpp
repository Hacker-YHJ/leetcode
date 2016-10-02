class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int aS = abbr.size();
    int wS = word.size();
    int i = 0, j = 0;
    int count = 0;
    while (j < aS && i < wS) {
      if (abbr[j] >= '0' && abbr[j] <= '9') {
        count = count * 10 + abbr[j] - '0';
        ++j;
        if (count == 0) return false;
        continue;
      } else {
        if (count > 0) {
          i += count;
          count = 0;
          continue;
        }
        if (word[i++] != abbr[j++]) return false;
      }
    }
    if (count > 0 && j == aS && i + count == wS) return true;
    if (count == 0 && j == aS && i == wS) return true;
    return false;
  }
};
