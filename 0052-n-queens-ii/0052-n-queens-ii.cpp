class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> cols, diag, antiDiag;
        int count = 0;
        backtrack(0, n, cols, diag, antiDiag, count);
        return count;
    }

    void backtrack(int row, int n,
                   unordered_set<int>& cols,
                   unordered_set<int>& diag,
                   unordered_set<int>& antiDiag,
                   int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag.count(row - col) || antiDiag.count(row + col))
                continue;
            // Place queen
            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);

            backtrack(row + 1, n, cols, diag, antiDiag, count);

            // Remove queen (backtrack)
            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }
    }
};
