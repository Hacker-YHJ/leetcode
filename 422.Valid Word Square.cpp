class Solution {
public:
  bool validWordSquare(vector<string>& words) {
    int s = words.size();
    if (s == 0) return true;
    if (s != words[0].size()) return false;
    for (int i = 0; i < s; ++i) {
      if (words[i][0] != words[0][i]) return false;
    }
    words.erase(words.begin());
    for (auto & s : words) {
      s.erase(s.begin());
    }
    words.erase(remove_if(words.begin(), words.end(), [](const string& s) { return s.empty(); }), words.end());
    return validWordSquare(words);
  }
};
