// Time Complexity: O(N!)
// Space Complexity: O(N)
// Explanation: Use backtracking to place queens column by column. Use three hash arrays (or bitmasks) to track attacked rows, upper diagonals, and lower diagonals. If placing a queen is safe, update hashes, recurse for next column, and then backtrack.

void solve(int col, int n, vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag, int& count) {
    if(col == n) {
        count++;
        return;
    }
    for(int row = 0; row < n; row++) {
        if(leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            solve(col + 1, n, leftRow, upperDiag, lowerDiag, count);
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}
int totalNQueens(int n) {
    int count = 0;
    vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(0, n, leftRow, upperDiag, lowerDiag, count);
    return count;
}

