int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    char max = '0', prev, curr; 
    char a,b,c;
    
    for (int i = 0; i < matrixRowSize; ++i) {
        for (int j = 0; j < matrixColSize; ++j) {
            if (i&&j&&matrix[i][j]!='0') {
                a = matrix[i-1][j-1], b = matrix[i-1][j], c = matrix[i][j-1];
                matrix[i][j] = 1 + (a < b ? (a < c ? a : c) : (b < c ? b : c));
            }
            max = max > matrix[i][j] ? max : matrix[i][j];
        }
    }
    return (max-'0')*(max-'0');
}

// 4ms
// 15%
