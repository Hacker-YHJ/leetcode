bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i = 0;
    int j = matrixColSize-1;
    int tmp = 0;
    while(i < matrixRowSize && j >=0 ) {
        tmp = matrix[i][j];
        if (target == tmp) return true;
        else if (target > tmp) ++i;
        else if (target < tmp) --j;
    }
    return false;
}

// 108ms
// 100%
