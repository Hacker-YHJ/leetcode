class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans[amount+1];
        ans[0] = 0;
        for (int i = 1; i <= amount; ++i) ans[i] = -1;
        for (int i = 0, j = coins.size(); i < j; ++i) {
            if (coins[i] > amount) continue;
            ans[coins[i]] = 1;
        }
        for (int i = 1; i <= amount; ++i) {
            if (-1 == ans[i]) continue;
            for (int p = 0, q = coins.size(); p < q; ++p) {
                if (i + coins[p] <= amount) {
                    ans[i+coins[p]] = ans[i] + 1);
                }
            }
        }
        return ans[amount];
    }
};

//132ms 20%
