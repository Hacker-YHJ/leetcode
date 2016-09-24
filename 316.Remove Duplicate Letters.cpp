class Solution {
public:
  string removeDuplicateLetters(string s) {
    string res;
    int count[26];
    memset(count, 0, sizeof(count));
    for (const auto& c : s) { count[c-'a']++; }

    while (!s.empty()) {
      int smallest = 0;
      int len = s.length();
      for (int i = 0; i < len; ++i) {
        if (s[i] < s[smallest]) { smallest = i; }
        if (--count[s[i]-'a'] == 0) {
          char c = s[smallest];
          res += c;
          for (int j = smallest + 1; j <= i; ++j) { count[s[j]-'a']++; }
          s = s.substr(smallest + 1);
          s.erase(std::remove(s.begin(), s.end(), c), s.end());
          break;
        }
      }
    }
    return res;
  }
};
