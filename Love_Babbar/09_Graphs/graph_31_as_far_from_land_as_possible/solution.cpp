// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Push all land cells (1s) into a queue and mark them as visited. Perform BFS outward. The last water cell processed gives the maximum distance. Track layers/steps during BFS.

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1) q.push({i, j});
        }
    }
    if(q.empty() || q.size() == n*n) return -1;
    int dist = -1;
    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [r, c] = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        dist++;
    }
    return dist;
}

