void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    int x, y;
    static enum {
		DEAD, LIVE
	} state[1 << 9];
	
	for(unsigned int bitmap = 0; bitmap < 1<<9; bitmap++) {
	    x = y = 0;
		for (int i = 1; y < 9; ++y) {
		    if (bitmap & i) ++x;
		    i <<= 1;
		}
		if(bitmap & 020) {
			if(x == 3 || x == 4)
				state[bitmap] = LIVE;
			else
				state[bitmap] = DEAD;
		} else {
			if(x == 3)
				state[bitmap] = LIVE;
			else
				state[bitmap] = DEAD;
		}
	}
	for (int i = 0; i < boardRowSize; ++i) {
	    x = 0;
	    x |= i ? (board[i-1][0]&1) << 2 : 0 << 2;
	    x |= (board[i][0]&1) << 1;
	    x |= i == boardRowSize-1 ? 0: (board[i+1][0]&1);
	    for (int j = 0; j < boardColSize; ++j) {
	        y = 0;
	        if (j != boardColSize-1) {
	            y |= i ? (board[i-1][j+1]&1) << 2 : 0 << 2;
	            y |= (board[i][j+1]&1) << 1;
	            y |= i == boardRowSize-1 ? 0 : board[i+1][j+1]&1;
	        }
	        x = ((x << 3) | y) & 0777;
	        board[i][j] |= state[x] << 1;
	    }
	}
	for (int i = 0; i < boardRowSize; ++i) {
	    for (int j = 0; j < boardColSize; ++j) {
	        board[i][j] >>= 1;
	    }
	}
    return board;
}

// 0ms 10%
