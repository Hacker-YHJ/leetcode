class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (!k) return 0;
    if (k > prices.size() / 2) {
      int profit = 0;
      for (int i = 1, j = prices.size(); i < j; i++) {
        prices[i] <= prices[i - 1] || (profit += prices[i] - prices[i - 1]);
      }
      return profit;
    }
    vector<vector<int> >arr(k, vector<int> {numeric_limits<int>::min(), 0});
    for (const auto& p : prices) {
      arr[0] = {max(arr[0][0], -p), max(arr[0][1], p + arr[0][0])};
      for (int i = 1; i < k; ++i) {
        arr[i] = {max(arr[i][0], arr[i-1][1] - p), max(arr[i][1], p + arr[i][0])};
      }
    }
    auto m = max_element(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
      });
    return (*m)[1];
  }
};
