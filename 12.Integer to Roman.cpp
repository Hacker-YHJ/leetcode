class Solution {
public:
  string intToRoman(int num) {
    vector<pair<int, string> > m {
      {1000, "M"},
      {900, "CM"},
      {800, "DCCC"},
      {700, "DCC"},
      {600, "DC"},
      {500, "D"},
      {400, "CD"},
      {100, "C"},
      {90, "XC"},
      {80, "LXXX"},
      {70, "LXX"},
      {60, "LX"},
      {50, "L"},
      {40, "XL"},
      {10, "X"},
      {9, "IX"},
      {8, "VIII"},
      {7, "VII"},
      {6, "VI"},
      {5, "V"},
      {4, "IV"},
      {1, "I"}
    };

    string res;
    int i = 0;
    while (num) {
      while (num < m[i].first) ++i;
      res += m[i].second;
      num -= m[i].first;
    }
    return res;
  }
};
