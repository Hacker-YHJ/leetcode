void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    if (0 == matrixRowSize && 0 == matrixColSize) return;
    int center = matrixRowSize/2;
    for (int i = 0; i < center; ++i) {
        for (int j = i; j < matrixColSize-i-1; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize-1-j][i];
            matrix[matrixRowSize-1-j][i] = matrix[matrixRowSize-1-i][matrixColSize-1-j];
            matrix[matrixRowSize-1-i][matrixColSize-1-j] = matrix[j][matrixColSize-1-i];
            matrix[j][matrixColSize-1-i] = tmp;
        }
    }
    return;
}

// 0ms 20.6%
