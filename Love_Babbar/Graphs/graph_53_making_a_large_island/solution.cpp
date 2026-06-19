// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Step 1: Traverse the grid. For each `1`, union it with its `1` neighbors. Calculate the size of each component using DSU. Step 2: Traverse again. For each `0`, check its 4 neighbors. Find unique ultimate parents among neighbors, sum their sizes, and add 1 (for the flipped `0`). Keep track of the maximum size found.

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(grid[row][col] == 0) continue;
            for(int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind], newc = col + dc[ind];
                if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1) {
                    int nodeNo = row * n + col;
                    int adjNodeNo = newr * n + newc;
                    ds.unionByRank(nodeNo, adjNodeNo);
                }
            }
        }
    }
    int mx = 0;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(grid[row][col] == 1) continue;
            unordered_set<int> components;
            for(int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind], newc = col + dc[ind];
                if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1) {
                    components.insert(ds.findUPar(newr * n + newc));
                }
            }
            int sizeTotal = 0;
            for(auto it : components) sizeTotal += ds.size[it];
            mx = max(mx, sizeTotal + 1);
        }
    }
    for(int cellNo = 0; cellNo < n * n; cellNo++) mx = max(mx, ds.size[ds.findUPar(cellNo)]);
    return mx;
}

