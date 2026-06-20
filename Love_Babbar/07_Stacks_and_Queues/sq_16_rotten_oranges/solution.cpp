// Time Complexity: O(rows * cols)
// Space Complexity: O(rows * cols)
// Explanation: Use a Queue for BFS. Find all initially rotten oranges and push them into the queue with time 0. Count total fresh oranges. Pop an orange, rot its adjacent fresh oranges, push them to the queue with `time + 1`, and decrement fresh count. Return the max time if fresh count is 0, else -1.

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];
    int cntFresh = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0;
            }
            if(grid[i][j] == 1) cntFresh++;
        }
    }
    int tm = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, cnt = 0;
    while(!q.empty()) {
        int r = q.front().first.first, c = q.front().first.second, t = q.front().second;
        tm = max(tm, t); q.pop();
        for(int i = 0; i < 4; i++) {
            int nrow = r + drow[i], ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    if(cnt != cntFresh) return -1;
    return tm;
}

