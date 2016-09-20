class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sell = 0;
    int cooldown = 0;
    int buy = numeric_limits<int>::min();
    for (auto i : prices) {
      int a = max(cooldown, sell);
      int b = max(cooldown - i, buy);
      int c = buy + i;
      cooldown = a;
      buy = b;
      sell = c;

    }
    return max(sell, cooldown);
  }
};
