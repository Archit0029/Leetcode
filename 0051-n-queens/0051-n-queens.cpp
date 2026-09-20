class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols, diag, antiDiag;
        backtrack(0, n, board, cols, diag, antiDiag, solutions);
        return solutions;
    }

    void backtrack(int row, int n, vector<string>& board,
                   unordered_set<int>& cols,
                   unordered_set<int>& diag,
                   unordered_set<int>& antiDiag,
                   vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag.count(row - col) || antiDiag.count(row + col))
                continue;
            // Place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);

            backtrack(row + 1, n, board, cols, diag, antiDiag, solutions);

            // Remove queen (backtrack)
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }
    }
};
