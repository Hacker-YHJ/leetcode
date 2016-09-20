int maxProfit(int* prices, int pricesSize) {
    int min = 0x7FFFFFFF;
    int maxProfit = 0;
    
    for (int j = 0; j < pricesSize; ++j) {
        maxProfit = maxProfit > prices[j] - min ? maxProfit : prices[j] - min;
        min = min < prices[j] ? min : prices[j];
    }
    return maxProfit;
}

// 4ms 5%
