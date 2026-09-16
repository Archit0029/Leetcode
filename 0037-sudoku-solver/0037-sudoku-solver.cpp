class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         backtrack(board);
    }
    
private:
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (backtrack(board)) return true;
                            board[i][j] = '.'; // undo choice
                        }
                    }
                    return false; // no valid digit found
                }
            }
        }
        return true; // all cells filled
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int k = 0; k < 9; k++) {
            // check row
            if (board[row][k] == c) return false;
            // check column
            if (board[k][col] == c) return false;
            // check 3x3 sub-box
            int boxRow = 3 * (row / 3) + k / 3;
            int boxCol = 3 * (col / 3) + k % 3;
            if (board[boxRow][boxCol] == c) return false;
        }
        return true;
    }
};