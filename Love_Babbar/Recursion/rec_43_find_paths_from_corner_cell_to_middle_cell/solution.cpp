// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Perform BFS or DFS starting from all 4 corners simultaneously or individually. At each cell `(r, c)`, the jump size is `val = grid[r][c]`. We can move to `(r+val, c)`, `(r-val, c)`, `(r, c+val)`, `(r, c-val)`. Target is `(N/2, N/2)`.

void solve(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    auto add = [&](int r, int c) { q.push({r, c}); vis[r][c] = true; };
    add(0, 0); add(0, n-1); add(n-1, 0); add(n-1, n-1);
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if(r == n/2 && c == n/2) { /* found path */ }
        int val = grid[r][c];
        for(int i=0; i<4; i++) {
            int nr = r + dr[i] * val, nc = c + dc[i] * val;
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

