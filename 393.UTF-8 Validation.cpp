class Solution {
public:
  bool validUtf8(vector<int>& data) {
    int len = data.size();
    int needed = 0;
    for (int i = 0; i < len; ++i) {
      int c = count(data[i]);
      if (c == 8) return false;
      if (needed) {
        if (c != 1) return false;
        needed--;
        continue;
      }
      if (c == 1) return false;
      if (c == 0) continue;
      needed = c - 1;
    }
    return !needed;
  }

  int count(unsigned char t) {
    if (!(t & 0x80)) return 0;

    int num = 0;
    while (t != 0) {
      if (!(t & 0x80)) break;
      num++;
      t = t << 1;
    }
    return num;
  }
};
