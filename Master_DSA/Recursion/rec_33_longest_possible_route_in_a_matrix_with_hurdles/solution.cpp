// Time Complexity: O(4^(M*N))
// Space Complexity: O(M*N)
// Explanation: Use Backtracking. Start from the source, mark it as visited, recursively find the longest path from all valid unvisited adjacent cells, add 1 to the maximum among them. Unmark the cell after returning.

void findLongestPath(vector<vector<int>>& mat, int i, int j, int di, int dj, int curr, int& max_dist, vector<vector<bool>>& vis) {
    if(i == di && j == dj) {
        max_dist = max(max_dist, curr);
        return;
    }
    vis[i][j] = true;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for(int k = 0; k < 4; k++) {
        int nr = i + dr[k], nc = j + dc[k];
        if(nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && mat[nr][nc] == 1 && !vis[nr][nc]) {
            findLongestPath(mat, nr, nc, di, dj, curr + 1, max_dist, vis);
        }
    }
    vis[i][j] = false;
}

