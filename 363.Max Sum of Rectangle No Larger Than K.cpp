class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int limit) {
    int width = matrix.size();
    int height = matrix[0].size();
    int res = numeric_limits<int>::min();
    for (int i = 0; i < height; ++i) {
      vector<int> tmp(width, 0);
      for (int j = i; j < height; ++j) {
        for (int k = 0; k < width; ++k) {
          tmp[k] += matrix[k][j];
        }
        set<int> accuSet;
        accuSet.insert(0);
        int curSum = 0, curMax = numeric_limits<int>::min();
        for (const auto& t : tmp) {
          curSum += t;
          set<int>::iterator it = accuSet.lower_bound(curSum - limit);
          if (it != accuSet.end()) curMax = max(curMax, curSum - *it);
          accuSet.insert(curSum);
        }
        res = max(res, curMax);
      }
    }
    return res;
  }
};
