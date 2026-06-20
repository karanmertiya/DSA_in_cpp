// Time Complexity: O(R * C * 4^L)
// Space Complexity: O(L)
// Explanation: Use DFS. For each cell, if it matches the first character of the word, start a DFS to look for the rest of the word in all 4 directions. Keep track of visited cells.

int dfs(vector<vector<char>>& mat, string& target, int r, int c, int idx) {
    if(idx == target.length()) return 1;
    if(r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size() || mat[r][c] != target[idx]) return 0;
    char temp = mat[r][c];
    mat[r][c] = '#';
    int found = dfs(mat, target, r + 1, c, idx + 1) +
                dfs(mat, target, r - 1, c, idx + 1) +
                dfs(mat, target, r, c + 1, idx + 1) +
                dfs(mat, target, r, c - 1, idx + 1);
    mat[r][c] = temp;
    return found;
}
int findOccurrence(vector<vector<char>>& mat, string target) {
    int count = 0;
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            if(mat[i][j] == target[0]) {
                count += dfs(mat, target, i, j, 0);
            }
        }
    }
    return count;
}

