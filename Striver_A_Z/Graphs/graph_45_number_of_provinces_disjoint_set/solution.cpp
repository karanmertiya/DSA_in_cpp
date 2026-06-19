// Time Complexity: O(V^2 * alpha)
// Space Complexity: O(V)
// Explanation: Initialize Disjoint Set for `n` nodes. Iterate through `isConnected` matrix. If `isConnected[i][j] == 1`, union `i` and `j`. After processing all edges, count how many nodes are their own parents (`parent[i] == i`).

// Use DisjointSet class from Kruskal's
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DisjointSet ds(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(isConnected[i][j] == 1) ds.unionByRank(i, j);
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(ds.findUPar(i) == i) cnt++;
    }
    return cnt;
}

