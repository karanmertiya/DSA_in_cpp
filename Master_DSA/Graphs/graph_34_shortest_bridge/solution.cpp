// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Step 1: Use DFS to find the first island. Mark all its cells (e.g., set to 2) and push them into a queue for BFS. Step 2: Perform multi-source BFS from the queue. Expand the island level by level. The first time we hit a `1` (which belongs to the second island), the number of layers expanded is the shortest bridge.

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
void dfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& q) {
    grid[r][c] = 2;
    q.push({r, c});
    int n = grid.size();
    for(int i=0; i<4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
            dfs(grid, nr, nc, q);
        }
    }
}
int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    bool found = false;
    for(int i=0; i<n && !found; i++) {
        for(int j=0; j<n && !found; j++) {
            if(grid[i][j] == 1) {
                dfs(grid, i, j, q);
                found = true;
            }
        }
    }
    int steps = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [r, c] = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if(grid[nr][nc] == 1) return steps;
                    if(grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
        steps++;
    }
    return steps;
}

