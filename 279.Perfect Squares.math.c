int numSquares(int n) {
    int sqrN;
    int tn = n;
    
    if (sqrN = (int)sqrt(n), sqrN*sqrN == n) return 1;
    
    // 4^k(8m+7)
    // three-square theorem
    while ((tn & 3) == 0) tn >>= 2;
    if ((tn & 7) == 7) return 4;
    
    for (int i = 1; i <= sqrN; ++i) {
        int sqrR, rest = n - i*i;
        if (sqrR = (int)sqrt(rest), (sqrR*sqrR == rest)) return 2;
    }
    
    return 3;
}

// 4ms
