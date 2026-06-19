// Time Complexity: O(4^(N*M))
// Space Complexity: O(N*M)
// Explanation: Use a global `max_dist` or pass it by reference. In `solve(r, c, dist)`, if `(r, c) == (dest_r, dest_c)`, `max_dist = max(max_dist, dist)` and return. Mark `(r, c)` as visited. Explore 4 directions. Unmark `(r, c)`.

int maxDist;
void solve(vector<vector<int>>& mat, int r, int c, int dr, int dc, int dist) {
    if(r == dr && c == dc) {
        maxDist = max(maxDist, dist);
        return;
    }
    mat[r][c] = 0; // mark visited
    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};
    for(int i = 0; i < 4; i++) {
        int nr = r + dRow[i];
        int nc = c + dCol[i];
        if(nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && mat[nr][nc] == 1) {
            solve(mat, nr, nc, dr, dc, dist + 1);
        }
    }
    mat[r][c] = 1; // unmark
}
int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd) {
    if(mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
    maxDist = -1;
    solve(mat, xs, ys, xd, yd, 0);
    return maxDist;
}

