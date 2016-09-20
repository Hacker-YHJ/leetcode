class Solution {
private:
  const int N = 10;
  vector<int> hours = {1, 2, 4, 8};
  vector<int> minutes = {1, 2, 4, 8, 16, 32};
  set<int> s;
  int getHours(vector<bool>::iterator s, vector<bool>::iterator e) {
      int res = 0;
      auto j = s;
      for (int i = 0; j < e; ++j, ++i) {
          if (*j) res += hours[i];
      }
      if (res < 12) return res;
      else return -1;
  }
  int getMinutes(vector<bool>::iterator s, vector<bool>::iterator e) {
      int res = 0;
      auto j = s;
      for (int i = 0; j < e; ++j, ++i) {
          if (*j) res += minutes[i];
      }
      if (res < 60) return res;
      else return -1;
  }
public:
    vector<string> readBinaryWatch(int num) {
        vector<bool> bitmask(N, false);
        fill(bitmask.begin(), bitmask.begin() + num, true);
        do {
            int hR = getHours(bitmask.begin(), bitmask.begin() + 4);
            int mR = getMinutes(bitmask.begin() + 4, bitmask.end());
            if (hR != -1 && mR != -1) {
                s.insert(hR * 60 + mR);
            }
        } while (prev_permutation(bitmask.begin(), bitmask.end()));
        vector<string> ans(s.size());
        transform(s.begin(), s.end(), ans.begin(), [](const int& s) {
            int hrs = s / 60;
            int mins = s % 60;
            string v = to_string(hrs) + ':' + (mins > 9 ? "" : "0");
            v += to_string(mins);
            return v;
        });
        return ans;
    }
};
