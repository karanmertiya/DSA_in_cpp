// Time Complexity: O(N * M * 8 * L)
// Space Complexity: O(1)
// Explanation: Iterate through the grid. For each matching starting character, check all 8 directions to see if the full word exists in a straight line.

vector<vector<int>> searchWord(vector<vector<char>> grid, string word){
    int R = grid.size(), C = grid[0].size(), L = word.length();
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<int>> ans;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(grid[r][c] == word[0]) {
                for(int dir = 0; dir < 8; dir++) {
                    int k, currR = r + dr[dir], currC = c + dc[dir];
                    for(k = 1; k < L; k++) {
                        if(currR < 0 || currR >= R || currC < 0 || currC >= C) break;
                        if(grid[currR][currC] != word[k]) break;
                        currR += dr[dir]; currC += dc[dir];
                    }
                    if(k == L) {
                        ans.push_back({r, c});
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

