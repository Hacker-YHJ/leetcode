class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        sum = matrix;
        if (matrix.empty() || matrix[0].empty()) return;
        int row = sum.size();
        int col = sum[0].size();
        for (int i = 1; i < row; ++i) {
            sum[i][0] += sum[i-1][0];
        }
        for (int j = 1; j < col; ++j) {
            sum[0][j] += sum[0][j-1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                sum[i][j] += (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1--;
        col1--;
        return sum[row2][col2] - (col1 >= 0 ? sum[row2][col1] : 0) - (row1 >= 0 ? sum[row1][col2] : 0) + (col1 >= 0 && row1 >= 0 ? sum[row1][col1] : 0);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
