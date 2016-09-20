class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int col[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int row[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int area[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c == '.') continue;
        int n = 1 << (c - '0' - 1);
        if (col[i] & n) return false;
        if (row[j] & n) return false;
        if (area[i / 3 * 3 + j / 3] & n) return false;
        col[i] |= n;
        row[j] |= n;
        area[i / 3 * 3 + j / 3] |= n;
      }
    }
    return true;
  }
};
