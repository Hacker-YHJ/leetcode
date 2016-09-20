double myPow(double x, int n) {
    double result = 1;
    double tx = x;
    int index;
    bool flag = n < 0;
    
    n = n < 0 ? -n : n;
    for (; n > 0; n >>= 1) {
        index = n & 0x1;
        if (index) {
            result *= tx*index;
        }
        tx *= tx;
    }
    return flag ? 1/result : result;
}

// 0ms 44%
