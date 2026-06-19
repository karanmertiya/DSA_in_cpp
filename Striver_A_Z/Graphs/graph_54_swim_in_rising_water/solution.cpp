// Time Complexity: O(N^2 log N)
// Space Complexity: O(N^2)
// Explanation: Use a priority queue to always process the cell with the minimum maximum-elevation so far. `pq` stores `(max_elev_in_path, r, c)`. Push `(grid[0][0], 0, 0)`. While pq is not empty, pop the minimum. If we reach `(n-1, n-1)`, return the `max_elev`. For each neighbor, the new max elevation is `max(max_elev, grid[nr][nc])`. Push to pq if not visited.

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    pq.push({grid[0][0], {0, 0}});
    vis[0][0] = 1;
    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
    while(!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int t = it.first, r = it.second.first, c = it.second.second;
        if(r == n - 1 && c == n - 1) return t;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                pq.push({max(t, grid[nr][nc]), {nr, nc}});
            }
        }
    }
    return 0;
}

