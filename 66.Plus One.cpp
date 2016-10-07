class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    bool carry = false;
    digits.back() += 1;
    for (auto p = digits.rbegin(); p != digits.rend(); ++p) {
      !carry || (*p += 1, carry = false);
      *p < 10 || (*p -= 10, carry = true);
    }
    if (carry) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
