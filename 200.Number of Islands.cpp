class Solution {
    typedef vector<char> VC;
    typedef vector<bool> VB;
    typedef vector<VC> VVC;
    typedef vector<VB> VVB;
    VVB flag;
    VVC board;
    int row, col;
public:
    bool visit(int i, int j) {
        if (!flag[i][j]) return false;
        if (board[i][j] != '1') return false;
        flag[i][j] = false;
        visit(i + 1, j);
        visit(i - 1, j);
        visit(i, j + 1);
        visit(i, j - 1);
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0;
        row = grid.size();
        col = grid[0].size();

        for (auto &v : grid) {
            v.push_back('0');
            v.insert(v.begin(), '0');
        }

        grid.push_back(VC(grid[0].size() + 2, '0'));
        grid.insert(grid.begin(), VC(grid[0].size() + 2, '0'));
        board = grid;
        flag = VVB(row + 2, VB(col + 2, true));
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (visit(i, j)) res++;
            }
        }
        return res;
    }
};
