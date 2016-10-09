class Solution {
public:
  vector<string> generatePossibleNextMoves(string str) {
    vector<string> res;
    for (int s = 0, e = str.size(); s < e - 1; ++s) {
      if (str[s] == '+' && str[s+1] == '+') {
        res.push_back(str);
        res.back()[s] = '-';
        res.back()[s+1] = '-';
      }
    }
    return res;
  }
};
