class Solution {
public:
  string toHex(int num) {
    if (num == 0) return "0";
    string table = "0123456789abcdef";
    deque<char> bytes;
    unsigned int t = num;
    while (t) {
      bytes.push_front(table[t & 0xf]);
      t >>= 4;
    }

    string ans;
    for (auto b : bytes) {
      ans += b;
    }
    return ans;
  }
};
