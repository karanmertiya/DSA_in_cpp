// Time Complexity: O(N^2 log N)
// Space Complexity: O(N^2)
// Explanation: Use a priority queue (Dijkstra variant). The cost to reach a cell is `max(cost_of_previous_cell, grid[r][c])`. Extract min cost cell, relax neighbors.

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int d = it[0], r = it[1], c = it[2];
        if(r == n-1 && c == n-1) return d;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n) {
                int next_d = max(d, grid[nr][nc]);
                if(next_d < dist[nr][nc]) {
                    dist[nr][nc] = next_d;
                    pq.push({next_d, nr, nc});
                }
            }
        }
    }
    return 0;
}

