class Solution {
public:
  string addBinary(string a, string b) {
    if (a.size() > b.size()) { a.swap(b); }
    auto bI = b.rbegin();
    auto aI = a.rbegin();
    bool carry = false;
    while (bI != b.rend() && aI != a.rend()) {
      *bI++ += *aI++ - '0';
    }
    bI = b.rbegin();
    while (bI != b.rend()) {
      !carry || (*bI += 1, carry = false);
      *bI <= '1' || (*bI -= 2, carry = true);
      ++bI;
    }
    if (carry) b.insert(0, "1");
    return b;
  }
};
