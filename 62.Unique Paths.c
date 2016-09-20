int uniquePaths(int m, int n) {
    int more, less = m > n ? (more = m, n) : (more = n, m);
    int arr[less];
    for (int j = 0; j < less; ++j) arr[j] = 1;
    for (int i = 1; i < more; ++i) {
        for (int j = 1; j < less; ++j) {
            arr[j] += arr[j-1];
        }
    }
    return arr[less-1];
}

// 0ms
// 1%
