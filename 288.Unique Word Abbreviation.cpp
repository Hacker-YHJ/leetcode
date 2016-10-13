class ValidWordAbbr {
  unordered_multimap<string, string> s;
public:
  ValidWordAbbr(vector<string> &dictionary) {
    for (auto const& str : dictionary) {
      s.insert(make_pair(toAbbv(str), str));
    }
  }

  bool isUnique(string word) {
    auto range = s.equal_range(toAbbv(word));
    for (auto it = range.first; it != range.second; ++it) {
      if (it->second != word) return false;
    }
    return true;
  }

  string toAbbv(string str) {
    if (str.length() < 3) {
      return str;
    } else {
      return str.front() + to_string(str.size() - 2) + str.back();
    }
  }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
