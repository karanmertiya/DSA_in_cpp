// Time Complexity: O(N * M)
// Space Complexity: O(N * M) worst case stack
// Explanation: Traverse the grid. When a '1' is found, increment island count and use DFS/BFS to mark all its 8-connected neighbors as '0' (or visited) to avoid recounting.

void dfs(int r, int c, vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    grid[r][c] = '0';
    for(int delrow = -1; delrow <= 1; delrow++) {
        for(int delcol = -1; delcol <= 1; delcol++) {
            int nrow = r + delrow;
            int ncol = c + delcol;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, grid);
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    if(n == 0) return 0;
    int m = grid[0].size();
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(i, j, grid);
            }
        }
    }
    return count;
}

