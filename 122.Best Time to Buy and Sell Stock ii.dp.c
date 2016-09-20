int maxProfit(int* prices, int pricesSize) {
    if (0 == pricesSize) return 0;
    int min = prices[0], result = 0;
    
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < prices[i-1]) result += prices[i-1] - min, min = prices[i];
    }
    result += prices[pricesSize-1] - min;
    return result;
}

// 4ms 12%
