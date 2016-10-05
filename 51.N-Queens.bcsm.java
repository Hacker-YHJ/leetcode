public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<List<String>> ();
        dfs(0, new boolean[n], new boolean[2*n], new boolean[2*n], new ArrayList<String>(n), result);
        return result;
    }
    
    public void dfs(int row, boolean[] cols, boolean[] d1, boolean[] d2, List<String> board, List<List<String>> result){
        if(row == cols.length) {
            List<String> boardc = new ArrayList<String> (board);
            result.add( boardc);
        }
        for(int col=0; col < cols.length; col++){
            int diagnal1 = row + col;
            int diagnal2 = row - col + cols.length;

            if (!cols[col] && !d1[diagnal1] && !d2[diagnal2]){
                char[] rowchar = new char[cols.length];
                Arrays.fill(rowchar,'.');
                rowchar[col] = 'Q';
                board.add(row, new String(rowchar));
                
                cols[col] = true; d1[diagnal1] = true; d2[diagnal2] = true;
                dfs(row+1, cols, d1, d2, board, result);
                cols[col] = false; d1[diagnal1] = false; d2[diagnal2] = false;
                board.remove(row);
            }
        }
    }
}