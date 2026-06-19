// Time Complexity: O(N * M * 4^L)
// Space Complexity: O(L) recursion stack
// Explanation: Start DFS from each cell that matches the first letter of the word. In DFS, check 4 neighbors. Mark current cell as visited (e.g. change to '#') before moving to neighbors, and unmark (backtrack) after exploring.

bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
    if(idx == word.length()) return true;
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = dfs(board, i+1, j, word, idx+1) ||
                 dfs(board, i-1, j, word, idx+1) ||
                 dfs(board, i, j+1, word, idx+1) ||
                 dfs(board, i, j-1, word, idx+1);
    board[i][j] = temp;
    return found;
}
bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) return true;
        }
    }
    return false;
}

