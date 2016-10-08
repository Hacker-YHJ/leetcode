class TicTacToe {
int n;
int *rows;
int *cols;
int dia[2];

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n) {
        rows = new int[n];
        cols = new int[n];
        memset(rows, 0, n * sizeof(int));
        memset(cols, 0, n * sizeof(int));
        memset(dia, 0, sizeof(dia));
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int v = (player << 1) - 3;
        rows[row] += v;
        cols[col] += v;
        if (row == col) dia[0] += v;
        if (row + col == n-1) dia[1] += v;

        if (rows[row] == n ||
            cols[col] == n ||
            dia[0] == n ||
            dia[1] == n) return 2;
        else if (rows[row] == -n||
            cols[col] == -n ||
            dia[0] == -n ||
            dia[1] == -n) return 1;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
