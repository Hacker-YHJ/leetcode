class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string str, int k) {
    int m[256];
    int num = 0;
    memset(m, 0, sizeof(m));
    int s = 0, e = 0, size = str.size();
    int mLen = 0;
    while (e < size) {
      if (m[str[e++]]++ == 0) { num++; }
      while (num > k) {
        if (--m[str[s++]] == 0) { num--; }
      }
      mLen = max(mLen, e - s);
    }
    return mLen;
  }
};
