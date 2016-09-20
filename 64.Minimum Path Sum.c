int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize==0&&gridColSize==0) return 0;
    for (int i = 1; i < gridRowSize; ++i) grid[i][0] += grid[i-1][0];
    for (int j = 1; j < gridColSize; ++j) grid[0][j] += grid[0][j-1];
    for (int i = 1; i < gridRowSize; ++i) {
        for (int j = 1; j < gridColSize; ++j) {
            grid[i][j] += grid[i][j-1] < grid[i-1][j] ? grid[i][j-1] : grid[i-1][j];
        }
    }
    return grid[gridRowSize-1][gridColSize-1];
}

// 20ms, 31%
