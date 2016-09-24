class Solution {
public:
  bool isSelfCrossing(vector<int>& x) {
    int size = x.size();
    if (size < 4) return false;
    int last = 3;
    for (; last < size; ++last) {
      if (x[last] >= x[last - 2] && x[last-1] <= x[last-3]) return true;
      if (last > 3 && x[last-1] == x[last-3] && x[last] + x[last-4] >= x[last-2]) return true;
      if (last > 4 && x[last-2] > x[last-4] && x[last-1] >= x[last-3] - x[last-5] && x[last-1] <= x[last-3] && x[last] >= x[last-2] - x[last-4]) return true;
    }
    return false;
  }
};
