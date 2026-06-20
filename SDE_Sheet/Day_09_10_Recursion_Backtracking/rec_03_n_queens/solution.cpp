// Time Complexity: O(N!) (Constraint)
// Space Complexity: O(N) (Constraint)
// Explanation: Backtracking. Try placing a queen in each row of the current column. Use `O(1)` lookups (Hashing logic) via arrays to check if row/diagonals are safe.

#include <vector>
#include <string>

void solve(int col, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& ans, std::vector<int>& leftRow, std::vector<int>& upperDiag, std::vector<int>& lowerDiag) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            
            solve(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);
            
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(0, n, board, ans, leftRow, upperDiag, lowerDiag);
    return ans;
}

