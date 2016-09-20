int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) return 0;
    int result = 1;
    int prev = 1;
    int down = 0;
    for (int i = 1; i <= ratingsSize; ++i) {
        if (i == ratingsSize || ratings[i] >= ratings[i-1]) {
            if (down > 0) {
                result += down*(down+1)/2;
                if (down >= prev) result += down - prev + 1;
                down = 0;
                prev = 1;
            }
            if (i < ratingsSize) {
                prev = ratings[i] == ratings[i-1] ? 1 : prev+1;
                result += prev;
            }
        }
        else ++down;
    }
    return result;
}

// 16ms
