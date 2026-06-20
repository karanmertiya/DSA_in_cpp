// Time Complexity: O(R * C)
// Space Complexity: O(R * C)
// Explanation: First, mark all adjacent cells of landmines as unsafe. Then start from each cell in the first column and use BFS or Backtracking to find the shortest path to the last column, avoiding unsafe cells.

int findShortestPath(vector<vector<int>> &mat) {
    int R = mat.size(), C = mat[0].size();
    vector<vector<int>> grid(R, vector<int>(C, 1));
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(mat[i][j] == 0) {
                grid[i][j] = 0;
                for(int k = 0; k < 4; k++) {
                    int nr = i + dr[k], nc = j + dc[k];
                    if(nr >= 0 && nr < R && nc >= 0 && nc < C) grid[nr][nc] = 0;
                }
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    for(int i = 0; i < R; i++) {
        if(grid[i][0] == 1) {
            q.push({{i, 0}, 1});
            vis[i][0] = true;
        }
    }
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        int r = curr.first.first, c = curr.first.second, dist = curr.second;
        if(c == C - 1) return dist;
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1 && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({{nr, nc}, dist + 1});
            }
        }
    }
    return -1;
}

