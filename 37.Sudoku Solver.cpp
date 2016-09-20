class Solution {
private:
    int flags[9] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100};
    int rowFlags[9] = {0};
    int colFlags[9] = {0};
    int secFlags[9] = {0};
    vector<pair<int, int>> blanks;
    int blankSize;
    int stopFlag = false;
public:
    void solveSudoku(vector<vector<char>>& board) {
        blanks.clear();
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    blanks.push_back(pair<int, int>(i, j));
                    continue;
                }
                rowFlags[i] |= flags[board[i][j]-'1'];
                colFlags[j] |= flags[board[i][j]-'1'];
                secFlags[i/3*3+j/3] |= flags[board[i][j]-'1'];
            }
        }
        blankSize = blanks.size();
        dfs(board, 0);
    }
    void dfs(vector<vector<char>>& board, int index) {
        if (stopFlag) return;
        if (index == blankSize) {
            stopFlag = true;
            return;
        }
        int posI = blanks[index].first;
        int posJ = blanks[index].second;
        for (int i = 0; i < 9; ++i) {
            if (rowFlags[posI] & flags[i]) continue;
            if (colFlags[posJ] & flags[i]) continue;
            if (secFlags[posI/3*3+posJ/3] & flags[i]) continue;
            rowFlags[posI] |= flags[i];
            colFlags[posJ] |= flags[i];
            secFlags[posI/3*3+posJ/3] |= flags[i];
            board[posI][posJ] = '1' + i;
            dfs(board, index+1);
            if (stopFlag) return;
            rowFlags[posI] &= ~flags[i];
            colFlags[posJ] &= ~flags[i];
            secFlags[posI/3*3+posJ/3] &= ~flags[i];
        }
        
    }
};

//4ms 88%
