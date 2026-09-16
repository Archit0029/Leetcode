class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Track used numbers in rows, cols, and boxes
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        
        // Initialize trackers
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = col[j][num] = box[(i/3)*3 + j/3][num] = true;
                }
            }
        }
        
        backtrack(board, row, col, box);
    }
    
private:
    bool backtrack(vector<vector<char>>& board, bool row[9][9], bool col[9][9], bool box[9][9]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 0; num < 9; num++) {
                        int boxIndex = (i/3)*3 + j/3;
                        if (!row[i][num] && !col[j][num] && !box[boxIndex][num]) {
                            board[i][j] = num + '1';
                            row[i][num] = col[j][num] = box[boxIndex][num] = true;
                            
                            if (backtrack(board, row, col, box)) return true;
                            
                            // undo
                            board[i][j] = '.';
                            row[i][num] = col[j][num] = box[boxIndex][num] = false;
                        }
                    }
                    return false; // no valid number fits
                }
            }
        }
        return true; // solved
    }
};