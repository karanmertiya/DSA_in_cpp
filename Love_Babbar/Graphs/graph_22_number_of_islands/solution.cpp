// Time Complexity: O(M * N)
// Space Complexity: O(M * N)
// Explanation: Iterate through each cell. When a '1' is found, increment the island count and start a DFS/BFS to mark all connected '1's as '0' (visited).

void dfs(vector<vector<char>>& grid, int r, int c) {
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') return;
    grid[r][c] = '0';
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

