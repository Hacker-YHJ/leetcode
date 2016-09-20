bool isPowerOfTwo(int n) {
    return !((n == 0) || (n==0x80000000) || (n & (n-1)));
}

// 0ms 44%
