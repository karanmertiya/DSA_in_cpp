// Time Complexity: O(9^(n*n))
// Space Complexity: O(1) excluding recursion stack
// Explanation: Iterate through each cell. If it's empty, try placing digits '1' to '9'. For each digit, check if it's valid in its row, column, and 3x3 subgrid. If valid, place it and recursively try to solve the rest. If a path leads to a solution, return true. Otherwise, backtrack (remove digit).

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == c) return false;
        if(board[row][i] == c) return false;
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == '.') {
                for(char c = '1'; c <= '9'; c++) {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(solve(board)) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

