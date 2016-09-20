class Solution {
public:
  string longestPalindrome(string s) {
    int oLen = s.size();
    char ns[oLen*2+1];
    int p[oLen*2+1];
    for (int i = 0, j = s.size(); i < j; ++i) {
      ns[2*i] = '#';
      ns[2*i+1] = s[i];
    }
    ns[2*s.size()] = '#';
    p[0] = 1;
    
    int maxI, maxV = 0, len = oLen*2+1, rI, rLen=0;
    for (int i = 0; i < len; ++i) {
      if (i < maxV) {
        p[i] = p[2*maxI-i] > p[maxI] + maxI - i ? p[maxI] + maxI - i : p[2*maxI-i];
      }
      else
        p[i] = 1;
      for (; i+p[i] < len && i-p[i] >= 0 && ns[i+p[i]] == ns[i-p[i]]; p[i]++);
      if (p[i] + i > maxV) {
        maxV = p[i] + i;
        maxI = i;
      }
      if (p[i] > rLen) {
        rI = i;
        rLen = p[i];
      }
    }
    char ans[rLen];
    for (int i = 0, j = rLen-1; i < j; ++i) {
      ans[i] = ns[rI-rLen+1+2*i+1];
    }
    ans[rLen-1] = '\0';
    string res(ans);
    return res;
  }
};
//4ms 92%
