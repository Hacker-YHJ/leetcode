class Solution {
private:
  int R, C;
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        R = board.size();
        C = board[0].size();
        vector<vector<bool> > flag(R, vector<bool>(C, false));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == 'X' || flag[i][j]) continue;
                helper(board, flag, i, j);
            }
        }
    }
    void helper(vector<vector<char> >& board, vector<vector<bool> >& flag, int row, int col) {
        vector<pair<int, int> > q;
        int i = 0;
        bool flip = true;
        q.push_back(make_pair(row, col));
        flag[row][col] = true;

        while (i < q.size()) {
            auto pos = q[i];
            if (pos.first == 0 ||
                pos.first == R - 1 ||
                pos.second == 0 ||
                pos.second == C - 1) flip = false;
            if (pos.first > 0 && !flag[pos.first-1][pos.second] && board[pos.first-1][pos.second] == 'O') {
                flag[pos.first-1][pos.second] = true;
                q.push_back(make_pair(pos.first - 1, pos.second));
            }
            if (pos.first < R - 1 && !flag[pos.first+1][pos.second] && board[pos.first+1][pos.second] == 'O') {
                flag[pos.first+1][pos.second] = true;
                q.push_back(make_pair(pos.first + 1, pos.second));
            }
            if (pos.second > 0 && !flag[pos.first][pos.second-1] && board[pos.first][pos.second-1] == 'O') {
                flag[pos.first][pos.second - 1] = true;
                q.push_back(make_pair(pos.first, pos.second-1));
            }
            if (pos.second < C - 1 && !flag[pos.first][pos.second+1] && board[pos.first][pos.second+1] == 'O') {
                flag[pos.first][pos.second + 1] = true;
                q.push_back(make_pair(pos.first, pos.second+1));
            }
            ++i;
        }
        if (flip) {
            for (const auto& p : q) {
                board[p.first][p.second] = 'X';
            }
        }
    }
};
