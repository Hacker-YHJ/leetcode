class Solution {
  int row, col;
public:
  int countBattleships(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return 0;
    row = board.size();
    col = board[0].size();
    int res = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (board[i][j] == 'X') {
          res++;
          dfs(board, i, j);
        }
      }
    }
    return res;
  }

  void dfs(vector<vector<char>> &board, int i, int j) {
    board[i][j] = '.';
    if (i > 0 && board[i-1][j] == 'X') dfs(board, i-1, j);
    if (i < row - 1 && board[i+1][j] == 'X') dfs(board, i+1, j);
    if (j > 0 && board[i][j-1] == 'X') dfs(board, i, j-1);
    if (j < col - 1 && board[i][j+1] == 'X') dfs(board, i, j+1);
  }
};
