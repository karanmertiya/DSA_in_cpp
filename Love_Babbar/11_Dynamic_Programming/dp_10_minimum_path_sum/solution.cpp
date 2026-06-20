// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: DP on Grids. Space optimize to 1D. `cur[j] = grid[i][j] + min(up, left)`.

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, 0);
    for(int i=0; i<n; i++) {
        vector<int> cur(m, 0);
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) cur[j] = grid[i][j];
            else {
                int up = grid[i][j], left = grid[i][j];
                if(i>0) up += prev[j]; else up += 1e9;
                if(j>0) left += cur[j-1]; else left += 1e9;
                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }
    return prev[m-1];
}

