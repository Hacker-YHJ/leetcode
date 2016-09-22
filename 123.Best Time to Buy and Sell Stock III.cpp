class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<vector<int> >arr(2, vector<int> {numeric_limits<int>::min(), 0});
    for (const auto& p : prices) {
      arr[0] = {max(arr[0][0], -p), max(arr[0][1], p + arr[0][0])};
      arr[1] = {max(arr[1][0], arr[0][1] - p), max(arr[1][1], p + arr[1][0])};
    }
    auto m = max_element(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
      });
    return (*m)[1];
  }
};
